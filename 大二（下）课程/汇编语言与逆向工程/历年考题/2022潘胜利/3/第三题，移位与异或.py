def decrypt(byte_429A38, byte_429A30):
    # 逆向操作：先异或，再逆向位操作
    Str = [0] * 8
    for i in range(8):
        # 逆向异或操作
        temp = byte_429A30[i] ^ byte_429A38[i]
        
        # 逆向位操作
        # 原始操作是: Str[i] = ((Str[i] & 1) << 7) | ((Str[i] & 0x80) >> 7) | (Str[i] & 0x7E)
        # 由于 ((Str[i] & 0x80) >> 7) 实际上没有改变字符的值，我们可以忽略它
        # 所以我们需要逆向 ((Str[i] & 1) << 7) 和 (Str[i] & 0x7E)
        
        # 逆向 (Str[i] & 1) << 7
        # 这一步将最低位移动到最高位，所以我们需要将最高位移动回最低位
        # 但是我们无法直接知道原始最低位的值，因此我们需要尝试所有可能的最低位值（0或1）
        
        # 由于我们不知道原始最低位的值，我们需要尝试所有可能的组合
        for bit in [0, 1]:
            # 假设原始最低位是bit，那么经过 (Str[i] & 1) << 7 后，最高位是bit
            # 所以我们需要将最高位移动回最低位
            candidate = (temp & 0xFE) | bit  # 将最高位移动回最低位
            # 现在我们需要逆向 (Str[i] & 0x7E) 操作
            # 原始操作是 Str[i] & 0x7E，所以我们需要恢复被掩码掉的位
            # 由于我们不知道原始值，我们需要尝试所有可能的组合
            # 但是我们可以尝试将候选值与掩码进行比较
            if (candidate & 0x7E) == (temp & 0x7E):
                Str[i] = candidate
                break
        else:
            # 如果没有找到合适的bit值，可能需要重新检查逻辑
            raise ValueError("无法解密字符")
    
    return ''.join([chr(c) for c in Str])

# 假设 byte_429A38 和 byte_429A30 是已知的
byte_429A38 = [0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D]  # 替换为实际值
byte_429A30 = [0x52, 0xC7, 0xC2, 0xCD, 0xEE, 0xEB, 0xFE, 0xF5]  # 替换为实际值

# 解密
result = decrypt(byte_429A38, byte_429A30)
print("可能的输入字符串是:", result)
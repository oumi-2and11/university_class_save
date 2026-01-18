
CREATE TABLE 学生基本信息表 (
  学号 varchar(255) NOT NULL,
  姓名 varchar(255) DEFAULT NULL,
  性别 varchar(255) DEFAULT NULL,
  专业 varchar(255) DEFAULT NULL,
  生日 varchar(255) DEFAULT NULL,
  身高 varchar(255) DEFAULT NULL,
  密码 varchar(255) DEFAULT NULL,
  PRIMARY KEY (学号)
);

INSERT INTO 学生基本信息表 VALUES ('104972072408', '杨剑', '男', '通信与信息系统', '1984-06-06', '1.76', '104972072408');
INSERT INTO 学生基本信息表 VALUES ('104972072409', '李春洋', '男', '通信与信息系统', '1984-08-06', '1.72', '104972072409');
INSERT INTO 学生基本信息表 VALUES ('104972072410', '孙磊君', '女', '通信与信息系统', '1984-08-09', '1.6', '104972072410');
INSERT INTO 学生基本信息表 VALUES ('104972072411', '谢惠琳', '女', '通信与信息系统', '1984-08-09', '1.6', '104972072411');
INSERT INTO 学生基本信息表 VALUES ('104972072412', '江根', '男', '通信与信息系统', '1984-08-09', '1.6', '104972072412');
INSERT INTO 学生基本信息表 VALUES ('104972072413', '魏军', '男', '通信与信息系统', '1984-08-09', '1.7', '104972072413');
INSERT INTO 学生基本信息表 VALUES ('104972072414', '阮巧玲', '女', '通信与信息系统', '1984-08-09', '1.65', '104972072414');
INSERT INTO 学生基本信息表 VALUES ('104972072415', '董明', '男', '通信与信息系统', '1984-08-09', '1.7', '104972072415');
INSERT INTO 学生基本信息表 VALUES ('104972072417', '黄玉成', '男', '通信与信息系统', '1984-08-09', '1.8', '104972072417');
INSERT INTO 学生基本信息表 VALUES ('104972072418', '任毅', '女', '通信与信息系统', '1984-08-08', '1.66', '104972072418');
INSERT INTO 学生基本信息表 VALUES ('104972072419', '柴婉君', '女', '通信与信息系统', '1984-08-08', '1.66', '104972072419');
INSERT INTO 学生基本信息表 VALUES ('104972072420', '郑培群', '男', '通信与信息系统', '1984-08-08', '1.8', '104972072420');
INSERT INTO 学生基本信息表 VALUES ('104972072421', '蔡柳青', '女', '通信与信息系统', '1984-08-21', '1.63', '104972072421');
INSERT INTO 学生基本信息表 VALUES ('104972072422', '张永昌', '男', '通信与信息系统', '1984-08-21', '1.73', '104972072422');
INSERT INTO 学生基本信息表 VALUES ('104972072423', '夏丽娜', '女', '通信与信息系统', '1984-05-12', '1.58', '104972072423');
INSERT INTO 学生基本信息表 VALUES ('104972072424', '陶金', '男', '通信与信息系统', '1984-05-12', '1.71', '104972072424');
INSERT INTO 学生基本信息表 VALUES ('104972072425', '钱程', '男', '通信与信息系统', '1984-05-12', '1.76', '104972072425');
INSERT INTO 学生基本信息表 VALUES ('104972072426', '闫文志', '男', '通信与信息系统', '1984-05-12', '1.75', '104972072426');
INSERT INTO 学生基本信息表 VALUES ('104972072427', '李常友', '男', '通信与信息系统', '1983-09-07', '1.72', '000');
INSERT INTO 学生基本信息表 VALUES ('104972072428', '王轲', '男', '通信与信息系统', '1984-05-12', '1.74', '104972072428');
INSERT INTO 学生基本信息表 VALUES ('104972072429', '闵慧', '女', '通信与信息系统', '1984-05-12', '1.6', '104972072429');
INSERT INTO 学生基本信息表 VALUES ('104972072430', '胡锐', '男', '通信与信息系统', '1984-05-12', '1.7', '104972072430');
INSERT INTO 学生基本信息表 VALUES ('104972072431', '黄海宁', '男', '通信与信息系统', '1984-05-12', '1.7', '104972072431');
INSERT INTO 学生基本信息表 VALUES ('104972072432', '郑捷航', '男', '通信与信息系统', '1984-05-12', '1.74', '104972072432');
INSERT INTO 学生基本信息表 VALUES ('104972072433', '刘钊', '男', '通信与信息系统', '1984-05-12', '1.7', '104972072433');
INSERT INTO 学生基本信息表 VALUES ('104972072434', '陈煜', '男', '通信与信息系统', '1984-05-12', '1.76', '104972072434');
INSERT INTO 学生基本信息表 VALUES ('104972072435', '黎雨露', '女', '通信与信息系统', '1984-05-12', '1.62', '104972072435');
INSERT INTO 学生基本信息表 VALUES ('104972072436', '李天林', '男', '通信与信息系统', '1984-05-12', '1.77', '104972072436');
INSERT INTO 学生基本信息表 VALUES ('104972072437', '郭一方', '男', '通信与信息系统', '1984-05-12', '1.73', '104972072437');

CREATE TABLE 成绩表 (
  学号 varchar(255) DEFAULT NULL,
  课程号 varchar(255) DEFAULT NULL,
  分数 varchar(255) DEFAULT NULL
);

INSERT INTO 成绩表 VALUES ('104972072408', '001', '90');
INSERT INTO 成绩表 VALUES ('104972072408', '003', '76');
INSERT INTO 成绩表 VALUES ('104972072408', '006', '72');
INSERT INTO 成绩表 VALUES ('104972072409', '003', '83');
INSERT INTO 成绩表 VALUES ('104972072409', '005', '80');
INSERT INTO 成绩表 VALUES ('104972072409', '006', '80');
INSERT INTO 成绩表 VALUES ('104972072410', '002', '80');
INSERT INTO 成绩表 VALUES ('104972072410', '003', '69');
INSERT INTO 成绩表 VALUES ('104972072411', '001', '79');
INSERT INTO 成绩表 VALUES ('104972072411', '004', '83');
INSERT INTO 成绩表 VALUES ('104972072412', '002', '71');
INSERT INTO 成绩表 VALUES ('104972072413', '003', '71');
INSERT INTO 成绩表 VALUES ('104972072414', '001', '76');
INSERT INTO 成绩表 VALUES ('104972072414', '006', '74');
INSERT INTO 成绩表 VALUES ('104972072415', '003', '83');
INSERT INTO 成绩表 VALUES ('104972072417', '003', '93');
INSERT INTO 成绩表 VALUES ('104972072418', '001', '86');
INSERT INTO 成绩表 VALUES ('104972072419', '003', '86');
INSERT INTO 成绩表 VALUES ('104972072419', '006', '86');
INSERT INTO 成绩表 VALUES ('104972072420', '005', '76');
INSERT INTO 成绩表 VALUES ('104972072420', '006', '72');
INSERT INTO 成绩表 VALUES ('104972072421', '001', '82');
INSERT INTO 成绩表 VALUES ('104972072422', '002', '84');
INSERT INTO 成绩表 VALUES ('104972072423', '003', '83');
INSERT INTO 成绩表 VALUES ('104972072424', '004', '85');
INSERT INTO 成绩表 VALUES ('104972072425', '005', '85');
INSERT INTO 成绩表 VALUES ('104972072426', '006', '86');
INSERT INTO 成绩表 VALUES ('104972072427', '001', '77');
INSERT INTO 成绩表 VALUES ('104972072427', '002', '78');
INSERT INTO 成绩表 VALUES ('104972072427', '003', '82');
INSERT INTO 成绩表 VALUES ('104972072427', '004', '83');
INSERT INTO 成绩表 VALUES ('104972072428', '001', '73');
INSERT INTO 成绩表 VALUES ('104972072429', '002', '76');
INSERT INTO 成绩表 VALUES ('104972072430', '003', '83');
INSERT INTO 成绩表 VALUES ('104972072431', '001', '73');
INSERT INTO 成绩表 VALUES ('104972072432', '002', '86');
INSERT INTO 成绩表 VALUES ('104972072433', '003', '87');
INSERT INTO 成绩表 VALUES ('104972072434', '004', '72');
INSERT INTO 成绩表 VALUES ('104972072435', '005', '78');
INSERT INTO 成绩表 VALUES ('104972072436', '006', '76');
INSERT INTO 成绩表 VALUES ('104972072437', '001', '82');
INSERT INTO 成绩表 VALUES ('104972072437', '006', '78');

CREATE TABLE 教师表 (
  登陆帐号 varchar(255) NOT NULL,
  教师 varchar(255) DEFAULT NULL,
  登陆密码 varchar(255) DEFAULT NULL,
  院系 varchar(255) DEFAULT NULL,
  性别 varchar(255) DEFAULT NULL,
  年龄 varchar(255) DEFAULT NULL,
  职称 varchar(255) DEFAULT NULL,
  PRIMARY KEY (登陆帐号)
);


INSERT INTO 教师表 VALUES ('1001', '李阳', '000', '外语学院', '男', '38', '教授');
INSERT INTO 教师表 VALUES ('1002', '肖攸安', '1002', '信息工程学院', '男', '33', '教授');
INSERT INTO 教师表 VALUES ('1003', '江雪梅', '1003', '信息工程学院', '女', '26', '讲师');
INSERT INTO 教师表 VALUES ('1004', '吕锋', '1004', '信息工程学院', '男', '50', '教授');
INSERT INTO 教师表 VALUES ('1005', '李方敏', '1005', '信息工程学院', '男', '36', '教授');
INSERT INTO 教师表 VALUES ('1006', '曾祥金', '1006', '理学院', '男', '56', '教授');

CREATE TABLE 管理员 (
  用户名 varchar(255) NOT NULL,
  密码 varchar(255) DEFAULT NULL,
  PRIMARY KEY (用户名)
);

INSERT INTO 管理员 VALUES ('sa', 'sa');

CREATE TABLE 课程信息表 (
  课程号 varchar(255) NOT NULL,
  课程名 varchar(255) DEFAULT NULL,
  学时 varchar(255) DEFAULT NULL,
  学分 varchar(255) DEFAULT NULL,
  学期 varchar(255) DEFAULT NULL,
  教师 varchar(255) DEFAULT NULL,
  PRIMARY KEY (课程号)
);

INSERT INTO 课程信息表 VALUES ('001', '英语', '60', '6', '2008年春', '李阳');
INSERT INTO 课程信息表 VALUES ('002', '密码学', '60', '3', '2008年春', '肖攸安');
INSERT INTO 课程信息表 VALUES ('003', '统计信号分析', '60', '2', '2008年春', '江雪梅');
INSERT INTO 课程信息表 VALUES ('004', '数据库技术', '60', '4', '2008年春', '吕锋');
INSERT INTO 课程信息表 VALUES ('005', '嵌入式系统', '60', '4', '2008年春', '李方敏');
INSERT INTO 课程信息表 VALUES ('006', '矩阵论', '60', '4', '2008年春', '曾祥金');
int main()
{
    int n = 0;
    int* p = 0;

    cin >> n;

    if (p == 0)
    {
        p = new int[n];
        if (p == 0)
        {
            return -1;
        }
        //else
        //{
        //    ;//
        //}
    }
    else
    {
        return -2;
    }

    if (p != 0)
    {
        p[0] = 0;
    }
    else
    {
        return -3;
    }

    if (p != 0)
    {
        delete p;
        p = 0;
    }
    else
    {
        return -4;
    }

    return 0;
}
#include "list.h"
#include "string.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//int main() {
//
//    int num = 0;
//    printf("1:Add\n");
//    printf("2:Multi\n");
//    while(true)
//    {
//        printf("please input 1 or 2:");
//        int cmd = 0;
//        scanf("%d", &cmd);
//        getchar();
//        printf("please input first num:");
//        char num1[100];
//        memset(num1, -1, 100);
//        scanf("%s", num1);
//        getchar();
//        printf("please input second num:");
//        char num2[100];
//        memset(num2, -1, 100);
//        scanf("%s", num2);
//        getchar();
//        List* list1 = createList();
//        num = 0;
//        while(num1[num] != -1 && num1[num] != 0)
//        {
//            list1 = InsertAfter(&list1,(num1[num]-'0'));
////            printf("%d\n", (num1[num]-'0'));
//            num ++;
//        }
//        num = 0;
//        List* list2 = createList();
//        while (num2[num] != -1 && num2[num] != 0 )
//        {
//            list2 = InsertAfter(&list2,(num2[num]-'0'));
////            printf("%d\n", (num2[num]-'0'));
//            num++;
//        }
//        List* res = NULL;
//        if (cmd == 1)
//        {
//            res = NumAdd(list1,list2);
//        } else{
//            res = NumMulti(list1,list2);
//        }
////        ShowListPositive(list1);
////        ShowListPositive(list2);
//        ShowListPositive(res);
//    }
//    return 0;
//}

//string calc_date(const char *cDateIn, int n) {
//    struct tm tmin;
//    struct tm *pTmIn = &tmin;
//    struct tm tmout;
//    struct tm *pTmOut = &tmout;
//
//    //由于windows下没有strptime函数，所以可以使用scanf来格式化
//    int year, month, day;
//    sscanf(cDateIn, "%d-%d-%d", &year, &month, &day);
//    pTmIn->tm_year = year - 1900;
//    pTmIn->tm_mon = month - 1;
//    pTmIn->tm_mday = day;
////    pTmIn->tm_isdst = -1;
//
//    /*将tm结构数据转换成1970年1月1日开始计算的秒数*/
//    time_t _tm = mktime(pTmIn);
//    cout << pTmIn->tm_yday << " " << pTmIn->tm_mon << " " << pTmIn->tm_mday << endl;
//
//    /*计算需要增加或者减少天数对应的秒数，结果是最终日期对应1970年1月1日开始计算的秒数*/
//    _tm += n * 60 * 60 * 24;
//
//    /*将time_t的信息转化真实世界的时间日期表示，结果由结构tm返回*/
//    pTmOut = localtime(&_tm);
//    cout << pTmOut->tm_yday << " " << pTmOut->tm_mon << " " << pTmOut->tm_mday << endl;
//
//    /*tm类型的时间转换。将tm按照%Y%m%d格式转化赋值到输出中*/
//    char buf[1024];
//    memset(buf, 0, sizeof(buf));
//    strftime(buf, sizeof(buf), "%Y-%m-%d", pTmOut);
//    cout << buf << endl;
//    return "";
////    string res(buf);
//}
//
//string GetNowTime()
//{
//    time_t t = time(0);
//    char tmp[32];
//    strftime(tmp, sizeof(tmp), "%Y-%m-%d",localtime(&t));
//    return (string)tmp;
//}
//
//
//int main()
//{
//    string now = GetNowTime();
//    cout << GetNowTime() << endl;
//    cout << calc_date(now.c_str(),3) << endl;
//}

vector<string> split(string& str)
{
    vector<string> res;
    string tmp;
    for (int i = 0;i < str.size();i++)
    {
        if (str[i] != '\t')
        {
            tmp += str[i];
        }else if (tmp.size() != 0){
            res.push_back(tmp);
            tmp.clear();
        }
    }
    if (tmp.size() != 0)
    {
        res.push_back(tmp);
    }
    return res;
}

int main()
{
//    string str("张伟\t2\t中国历史\t2021-03-04\t\t1");
//    vector<string> res = split(str);
//    for (int i = 0;i < res.size();i++)
//    {
//        cout << res[i] << endl;
//    }

    string str("1");
    cout << atoi(str.c_str()) << endl;
}
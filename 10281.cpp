#include <bits/stdc++.h>

using namespace std;

void timeCout(int h, int m, int s)
{
    int arr[]={h,m,s};

    for(int i=0; i<3; i++)
    {

        if(arr[i]/10==0)
        {
            cout << "0";
            cout << arr[i];
        }
        else
            cout << arr[i];
        if(i<2)
            cout << ":";
    }
    cout << " ";


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double h,m,s;
    double speed, prevTime, time, durTime, distance=0,d;
    char ch;
    int flag=1;

    while(scanf("%lf:%lf:%lf", &h, &m, &s) != EOF)
    {

        scanf("%c", &ch);

        if(ch==' ')
        {
            time=s + m*60 + (h*3600);
            if(flag==0)
            {
                durTime=time-prevTime;
                durTime/=3600;
                d=speed*durTime;
                distance+=d;
                            }
            scanf("%lf", &speed);
            prevTime=time;
            flag=0;
        }
        else
        {

            time=s + m*60 + (h*3600);
            durTime=time-prevTime;
            durTime/=3600;
            d=speed*durTime;
            distance+=d;

            timeCout(h,m,s);
            cout << setprecision(2) << fixed << distance << " km" << endl;
            prevTime=time;

        }
    }
    return 0;
}

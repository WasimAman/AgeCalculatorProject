#include<stdio.h>

int main(){
    int bd,bm,by,cd,cm,cy,day,week,month,year,hour,min,sec,i,a,count=0;
    printf("enter date of birth ");
    scanf("%d%d%d",&bd,&bm,&by);
    printf("enter current date ");
    scanf("%d%d%d",&cd,&cm,&cy);

    if(bd>1 && bd<=31 && cd>1 && cd<=31 && bm>1 && bm<=12 && cm>1 && cm<=12){
        if(cd<bd){
            if(cm==1 && cm==3 && cm==5 && cm==7 && cm==8 && cm==10 && cm==12){
                day=(cd+31)-bd;
                cm--;
            }
            else if(cm==4 && cm==6 && cm==9 && cm==11){
                day=(cd+30)-bd;
                cm--;
            }
            else{
                if(cy%4==0 || (cy%100==0 && cy%400==0)){
                    day=(cd+29)-bd;
                    cm--;
                }
                else{
                    day=(cd+28)-bd;
                    cm--;
                }
            }
        }
        else{
            day=cd-bd;
        }
        if(cm<bm){
            cy-=1;
            month=(cm+12)-bm;
        }
        else{
            month=cm-bm;
        }
    }
    else{
        printf("invalide data....");
    }
    year=cy-by;
    printf("\nyour age is %dyears %dmonths %d days\n",year,month,day);

    month=(year*12)+month;
    printf("your age is %dmonths %d days\n",month,day);

    day+=year*365;
    month=month%12;
    day+=month*30;
    for(i=1;i<=month;i++){
        if(i%3==0){
            count++;
        }
    }
    for(i=1;i<=year;i++){
        if(i%4==0){
            count++;
        }
    }
    day+=count;
    week=day/7;
    a=day%7;
    printf("your age is %dweeks %ddays\n",week,a);
    printf("your age is %ddays\n",day);

    hour=day*24;
    printf("your age is %dhours\n",hour);

    min=hour*60;
    printf("your age is %dminutes\n",min);

    sec=min*60;
    printf("your age is %dseconds\n",sec);

    return 0;
}

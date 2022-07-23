#include<iostream>
#include<iomanip>
#include <bits/stdc++.h>
using namespace std;
//match details
class match_details
{
public:
    string team1_n,team2_n,team1_captain,team2_captain,date,time,stadium,country;
    int overs;
    match_details()
    {
        cout<<"ENTER TEAM 1 NAME: ";
        getline(cin,team1_n);
        cout<<"\nENTER TEAM 2 NAME: ";
        getline(cin,team2_n);
        cout<<"\nENTER TEAM 1 CAPTAIN:  ";
        getline(cin,team1_captain);
        cout<<"\nENTER TEAM 2 CAPTAIN:  ";
        getline(cin,team2_captain);
        cout<<"\nENTER DATE:  ";
        getline(cin,date);
        cout<<"\nENTER TIME:  ";
        getline(cin,time);
        cout<<"\nENTER STADIUM:   ";
        getline(cin,stadium);
        cout<<"\nENTER COUNTRY:   ";
        getline(cin,country);
        cout<<"\nENTER THE NUMBER OF OVERS:   ";
        cin>>overs;
        cout<<"\n";
    }
    //toss
    void toss(int a,int b)
    {
        if(a==1){cout<<"\n"<<setw(100)<<team1_n<<"   WON THE TOSS \n ";}
        else{cout<<"\n"<<setw(100)<<team2_n<<"   WON THE TOSS\n ";}
        cout<<"\n";
        if(b==1){cout<<setw(116)<<"AND CHOOSE TO BAT   ";}
        else{cout<<setw(116)<<"AND CHOOSE TO BOWL   ";}
        if((a==1 && b==2)||(a==2 && b==1 ))
        {
            swap(team1_n,team2_n);
            swap(team1_captain,team2_captain);
        }
    }
    //printing match details
    void show_match_details()
    {
        cout<<setw(94)<<"  ***  "<<team1_n;
        cout<<"    VS   "<<team2_n<<"  ***  "<<endl;
        cout<<"\n"<<setw(94)<<"       "<<team1_captain;
        cout<<"    VS   "<<team2_captain<<"       "<<endl;
        cout<<"\n"<<setw(110)<<"       OVERS   :   "<<overs<<endl;
        cout<<"\n"<<setw(92)<<"DATE : "<<date<<setw(20)<<"TIME  : "<<time<<endl;
        cout<<"\n"<<setw(95)<<"STADIUM : "<<stadium<<setw(20)<<"COUNTRY  : "<<country<<endl;
    }

};
//team details
class team
{
public:
    int player_order;
    string  player_fname,player_lname,role;
    void set_team_details()
    {
        cout<<"PLAYER  ORDER : ";
        cin>>player_order;
        cout<<"PLAYER  FIRST NAME : ";
        cin>>player_fname;
        cout<<"PLAYER  LAST NAME : ";
        cin>>player_lname;
        cout<<"Player Role : ";
        cin>>role;
        cout<<"\n";
    }
    void print_team_details()
    {
        cout<<"    "<<player_order<<setw(20)<<player_fname<<" "<<player_lname<<setw(20)<<role;
        cout<<endl;
    }

};
class batting
{public:
    int p_runs,p_balls,s4,s6;
    string p_fname,p_lname;
     void set_p_runs(int pr)
    {
        p_runs=pr;

    }
    int get_p_runs()
    {
        return p_runs;
    }
    void set_p_balls(int pb)
    {
        p_balls=pb;
    }
    int get_p_balls()
    {
        return p_balls;
    }
    void set_p_s4(int f)
    {
        s4=f;
    }
    int  get_p_s4()
    {
        return s4;
    }
    void set_p_s6(int s)
    {
        s6=s;
    }
    int get_p_s6()
    {
        return s6;
    }
     friend void bat_set_func(batting *,int ,int ,int ,int );
};
class bowling
{
 public:
     int b_runs=0,b_overs=0,b_wickets=0;
     double b_economy;
     string b_name;
     void set_b_name(string bn)
     {
         b_name=bn;
     }
     string get_b_name()
     {
         return b_name;
     }
     void set_b_runs(int br=0)
     {
         this->b_runs=this->b_runs+br;
     }
     int get_b_runs()
     {
         return b_runs;
     }
     void set_b_overs(int bo=0)
     {
         this->b_overs=this->b_overs+bo;
     }
     int get_b_overs()
     {
         return b_overs;
     }
     void set_b_wickets(int bw=0)
     {
         this->b_wickets=this->b_wickets+bw;
     }
     int get_b_wickets()
     {
         return b_wickets;
     }
      double get_b_economy()
     {
         b_economy=double(b_runs/b_overs);
         return b_economy;
     }
     friend void bow_set_func(bowling *,int,int,int);

};
void swap_main_func(int &m11,int &m11_r,int &m11_b,int &m11_s4,int &m11_s6,int &n11,int &n11_r,int &n11_b,int &n11_s4,int &n11_s6)
{
     swap(m11,n11);
     swap(m11_r,n11_r);
     swap(m11_b,n11_b);
     swap(m11_s4,n11_s4);
     swap(m11_s6,n11_s6);

}
 void runs_func(int co,int &x11,int &x11_r,int &x11_b,int &x11_s4,int &x11_s6,int &y11,int &y11_r,int &y11_b,int &y11_s4,int &y11_s6)
{
    //strike
    if(co==1 || co==3|| co==5)
    {
     x11_r=x11_r+co;
     x11_b=x11_b+1;
     swap_main_func(x11,x11_r,x11_b,x11_s4,x11_s6,y11,y11_r,y11_b,y11_s4,y11_s6);
    }
    else
    {
    x11_r=x11_r+co;
    x11_b=x11_b+1;
    //update for boundaries
    switch(co)
    {
        case 4: x11_s4=x11_s4+1;
                break;
        case 6: x11_s6=x11_s6+1;
                break;
    }
    }
}
void bat_set_func(batting *pb,int z1_r,int z1_b,int z1_s4,int z1_s6)
{
    pb->set_p_runs(z1_r);
    pb->set_p_balls(z1_b);
    pb->set_p_s4(z1_s4);
    pb->set_p_s6(z1_s6);

}
void bow_set_func(bowling *bb,int z2_r,int z2_o,int z2_w)
{
    bb->set_b_runs(z2_r);
    bb->set_b_overs(z2_o);
    bb->set_b_wickets(z2_w);

}
int noball_func(int &v1_r,int &v1_s4,int &v1_s6)
{
    int v1=0,temp5=0,temp6=0;
    while(temp6<=1)
    {
    temp6++;
    cout<<"\n ENTER THE  RUNS SCORED : "<<endl;
    cin>>temp5;
    v1=v1+temp5;
    if(temp5!=0)
    {
        v1_r=v1_r+temp5;
        if(temp5==4){v1_s4++;}
        if(temp5==6){v1_s6++;};
    }
    if(temp6==1){cout<<" \n FREE HIT  :";}
    }
    return v1;

}

int main()
{
    match_details m;
    int to1,to2;
    cout<<"ENTER  WHICH WON THE TOSS   1: TEAM1  2:TEAM2"<<endl;
    cin>>to1;
    cout<<"ENTER   1:BATTING   2:BOWLING ";
    cin>>to2;
    m.show_match_details();
    m.toss(to1,to2);
    team *t1[11],*t2[11];
    cout<<endl;
    cout<<"  ENTER  "<<m.team1_n<<" TEAM    DETAILS   "<<endl;
    cout<<endl;
    for(int i=1;i<=11;i++)
    {
        t1[i]=new team;
    }
    for(int i=1;i<=11;i++)
    {
        t1[i]->set_team_details();
    }
    cout<<endl;
    cout<<"  ENTER  "<<m.team2_n<<" TEAM    DETAILS   "<<endl;
    cout<<endl;
    for(int i=1;i<=11;i++)
    {
        t2[i]=new team;
    }
    for(int i=1;i<=11;i++)
    {
        t2[i]->set_team_details();
    }
    cout<<"PLAYER ORDER"<<setw(20)<<" PLAYER  NAME "<<setw(25)<<" PLAYER ROLE "<<endl;
    cout<<endl;
    for(int i=1;i<=11;i++)
    {
        t1[i]->print_team_details();
    }
    cout<<"\n"<<endl;
    cout<<"PLAYER ORDER"<<setw(20)<<" PLAYER  NAME "<<setw(25)<<" PLAYER ROLE "<<endl;
    cout<<endl;
    for(int i=1;i<=11;i++)
    {
        t2[i]->print_team_details();
    }
    cout<<"\n  1 st INNINGS    \n"<<endl;
    // creating objects for 11 players of class batting
    batting *ba1[11];
    for(int i1=1;i1<=11;i1++)
    {
        ba1[i1]=new batting;
        ba1[i1]->p_fname=t1[i1]->player_fname;
        ba1[i1]->p_lname=t1[i1]->player_lname;
    }
    // creating objects for 5 bowlers of class bowling
    cout<<"   ENTER BOWLER NAMES(5) "<<endl;
    bowling *bo1[6];
    for(int j1=1;j1<=5;j1++)
    {
        bo1[j1]=new bowling;
        cout<<"\nENTER BOWLER NAME "<<j1<<" :"<<endl;
        string b1_name;
        cin>>b1_name;
        bo1[j1]->set_b_name(b1_name);
    }
    cout<<"\n"<<endl;
    //for user enter code: 66
    cout<<"FOR USER ENTER 66"<<endl;
    int nov=m.overs,i1runs[nov-1][6],t1_truns=0,t1_balls=0,t1_wickets=0,temp1,temp2=0,temp3=1,extras_1=0,all_out1=0;
    int x1=1,y1=2,x1_r=0,y1_r=0,x1_s4=0,y1_s4=0,y1_s6=0,x1_s6=0,x1_b=0,y1_b=0;
    for(int i11=0;(i11<=nov-1)&&(all_out1==0);i11++)
    {
        //for bpwler
        int w1,w1_r=0,w1_o=0,w1_w=0;
        cout<<"\n ENTER BOWLER ORDER :\n";
        cin>>w1;
        cout<<"\n";
        for(int j11=0;(j11<=5)&&(all_out1==0);j11++)
        {
            int code=0;
            cout<<"("<<(i11)<<"."<<(j11+1)<<") :";
            cin>>code;
            cout<<"  ";
            if(code<7)
            {
                w1_r=w1_r+code;
                runs_func(code,x1,x1_r,x1_b,x1_s4,x1_s6,y1,y1_r,y1_b,y1_s4,y1_s6);
            }
            else
            {
                switch(code)
                {
                    //user function :code=66
                    case 66: j11-=1;
                             int u1;
                             cout<<"\n";
                             cout<<"ENTER :-----    1 : MATCH DETAILS  -----  2 : TEAM DETAILS -----  3 : UPDATED SCORE  -----\n";
                             cin>>u1;
                             switch(u1)
                             {
                                 case 1:m.show_match_details();
                                        break;
                                 case 2:cout<<"\n";
                                        cout<<"\t\t\t\t**  "<<m.team1_n<<"  **\n";
                                        cout<<"PLAYER ORDER"<<setw(20)<<" PLAYER  NAME "<<setw(25)<<" PLAYER ROLE "<<endl;
                                        cout<<endl;
                                        for(int i=1;i<=11;i++)
                                        {
                                           t1[i]->print_team_details();
                                        }
                                        break;
                                 case 3:cout<<"\n";
                                        int u11=t1_truns+extras_1+x1_r+y1_r;
                                        cout<<"\t\t "<<u11<<" - "<<t1_wickets<<"\t\tOVERS :"<<i11<<"."<<j11+1<<"\t\tEXTRAS :"<<extras_1<<"\n";
                                        cout<<"\t\t"<<ba1[x1]->p_fname<<" "<<ba1[x1]->p_lname<<" --- "<<x1_r<<" ("<<x1_b<<") \n";
                                        cout<<"\t\t"<<ba1[y1]->p_fname<<" "<<ba1[y1]->p_lname<<" --- "<<y1_r<<" ("<<y1_b<<") \n";
                                        break;

                             }
                             break;
                    //wicket :code=77
                    case 77: temp1=std::max(x1,y1);
                             w1_w=w1_w+1;
                             t1_wickets++;
                             //last wicket
                             cout<<"\n ENTER IF ANY RUNS SCROED BY THE PLAYER :"<<endl;
                             cin>>temp2;
                             x1_r=x1_r+temp2;
                             if(temp1==11)
                             {
                                 all_out1=1;

                             }
                             //adding new player
                             else
                             {
                                 //in case of run pout
                                cout<<"\n ENTER 1:STRIKER OR  2:NON STRIKER   \n"<<endl;
                                cin>>temp3;
                                if(temp3==1)
                                {
                                t1_truns=t1_truns+x1_r;
                                bat_set_func(ba1[x1],x1_r,x1_b,x1_s4,x1_s6);
                                x1=temp1+1,x1_r=0;x1_b=0;x1_s4=0,x1_s6=0;
                                //in case of run out
                                if(temp2%2==0){swap_main_func(x1,x1_r,x1_b,x1_s4,x1_s6,y1,y1_r,y1_b,y1_s4,y1_s6);}
                                }
                                else
                                {
                                t1_truns=t1_truns+y1_r;
                                bat_set_func(ba1[y1],y1_r,y1_b,y1_s4,y1_s6);
                                y1=temp1+1,y1_r=0;y1_b=0;y1_s4=0,y1_s6=0;
                                if(temp2%2==0){swap_main_func(x1,x1_r,x1_b,x1_s4,x1_s6,y1,y1_r,y1_b,y1_s4,y1_s6);}
                                }

                             }
                             break;
                    //wide:code=88
                    case 88: extras_1++;
                             w1_r=w1_r+1;
                             j11--;
                             break;
                    //no ball:code=99
                    case 99:extras_1++;
                            w1_r=w1_r+1;
                            i1runs[i11][j11]=noball_func(x1_r,x1_s4,x1_s6);
                            break;
                    default :j11-=1;
                             cout<<" INVALID INPUT :"<<endl;
                             break;


                }

            }
        }
        w1_o=w1_o+1;
        bow_set_func(bo1[w1],w1_r,w1_o,w1_w);
        swap_main_func(x1,x1_r,x1_b,x1_s4,x1_s6,y1,y1_r,y1_b,y1_s4,y1_s6);

    }
    t1_truns=t1_truns+x1_r+y1_r+extras_1;
    int h11=max(x1,y1);
    bat_set_func(ba1[x1],x1_r,x1_b,x1_s4,x1_s6);
    bat_set_func(ba1[y1],y1_r,y1_b,y1_s4,y1_s6);
    cout<<"\n  2 nd INNINGS    \n"<<endl;
    // creating objects for 11 players of class batting
    batting *ba2[11];
    for(int i2=1;i2<=11;i2++)
    {
        ba2[i2]=new batting;
        ba2[i2]->p_fname=t2[i2]->player_fname;
        ba2[i2]->p_lname=t2[i2]->player_lname;
    }
    // creating objects for 5 bowlers of class bowling
    cout<<"   ENTER BOWLER NAMES(5) "<<endl;
    bowling *bo2[6];
    for(int j2=1;j2<=5;j2++)
    {
        bo2[j2]=new bowling;
        cout<<"\nENTER BOWLER NAME "<<j2<<" :";
        string b2_name;
        cin>>b2_name;
        bo2[j2]->set_b_name(b2_name);
    }
    cout<<"\n"<<endl;
    //for user enter code: 66
    cout<<"FOR USER ENTER 66"<<endl;
    int i2runs[nov-1][6],t2_truns=0,t2_wickets=0,extras_2=0,all_out2=0;
    int x2=1,y2=2,x2_r=0,y2_r=0,x2_s4=0,y2_s4=0,y2_s6=0,x2_s6=0,x2_b=0,y2_b=0,over_r2,target=t1_truns+1;
    temp1,temp2=0,temp3=1;
    for(int i22=0;(i22<=nov-1)&&(all_out2==0)&&(t2_truns+x2_r+y2_r+extras_2)<target;i22++)
    {
        //for bowler
        int w2,w2_r=0,w2_o=0,w2_w=0;
        cout<<"\n ENTER BOWLER ORDER :\n";
        cin>>w2;
        cout<<"\n";
        for(int j22=0;(j22<=5)&&(all_out2==0)&&(t2_truns+x2_r+y2_r+extras_2)<target;j22++)
        {
            int code=0;
            cout<<"("<<(i22)<<"."<<(j22+1)<<") :";
            cin>>code;
            cout<<"  ";
            if(code<7)
            {
                w2_r=w2_r+code;
                runs_func(code,x2,x2_r,x2_b,x2_s4,x2_s6,y2,y2_r,y2_b,y2_s4,y2_s6);
            }
            else
            {
                switch(code)
                {
                    //user :code=66
                    case 66: j22-=1;
                             int u2;
                             cout<<"\n";
                             cout<<"ENTER :-----    1 : MATCH DETAILS  -----  2 : TEAM DETAILS -----  3 : UPDATED SCORE  -----\n";
                             cin>>u2;
                             switch(u2)
                             {
                                 case 1:m.show_match_details();
                                        break;
                                 case 2:cout<<"\n";
                                        cout<<"\t\t\t\t**  "<<m.team2_n<<"  **\n";
                                        cout<<"PLAYER ORDER"<<setw(20)<<" PLAYER  NAME "<<setw(25)<<" PLAYER ROLE "<<endl;
                                        cout<<endl;
                                        for(int i=1;i<=11;i++)
                                        {
                                           t2[i]->print_team_details();
                                        }
                                        break;
                                 case 3:cout<<"\n";
                                        int u22=t2_truns+extras_2+x2_r+y2_r;
                                        cout<<"\t\t "<<u22<<" - "<<t2_wickets<<"\t\tOVERS :"<<i22+1<<"."<<j22+1<<"\t\tEXTRAS :"<<extras_2<<"\t\t**TARGET** :"<<target<<"\n";
                                        cout<<"\t\t"<<ba2[x2]->p_fname<<" "<<ba2[x2]->p_lname<<" --- "<<x2_r<<" ("<<x2_b<<") \n";
                                        cout<<"\t\t"<<ba2[y2]->p_fname<<" "<<ba2[y2]->p_lname<<" --- "<<y2_r<<" ("<<y2_b<<") \n";
                                        break;
                             }
                             break;
                    //wicket :code=77
                    case 77: temp1=std::max(x2,y2);
                             w2_w=w2_w+1;
                             t2_wickets++;
                             //last wicket
                             cout<<"\n ENTER IF ANY RUNS SCROED BY THE PLAYER :"<<endl;
                             cin>>temp2;
                             x2_r=x2_r+temp2;
                             if(temp1==11)
                             {
                                 all_out2=1;

                             }
                             //adding new player
                             else
                             {
                                 //in case of run pout
                                cout<<"\n ENTER 1:STRIKER OR  2:NON STRIKER   \n"<<endl;
                                cin>>temp3;
                                if(temp3==1)
                                {
                                t2_truns=t2_truns+x2_r;
                                bat_set_func(ba2[x2],x2_r,x2_b,x2_s4,x2_s6);
                                x2=temp1+1,x2_r=0;x2_b=0;x2_s4=0,x2_s6=0;
                                //in case of run out
                                if(temp2%2==0){swap_main_func(x2,x2_r,x2_b,x2_s4,x2_s6,y2,y2_r,y2_b,y2_s4,y2_s6);}
                                }
                                else
                                {
                                t2_truns=t2_truns+y2_r;
                                bat_set_func(ba2[y2],y2_r,y2_b,y2_s4,y2_s6);
                                y2=temp1+1,y2_r=0;y2_b=0;y2_s4=0,y2_s6=0;
                                if(temp2%2==0){swap_main_func(x2,x2_r,x2_b,x2_s4,x2_s6,y2,y2_r,y2_b,y2_s4,y2_s6);}
                                }

                             }
                             break;
                    //wide:code=88
                    case 88: extras_2++;
                             w2_r=w2_r+1;
                             j22--;
                             break;
                    //no ball:code=99
                    case 99:extras_2++;
                            w2_r=w2_r+1;
                            i2runs[i22][j22]=noball_func(x2_r,x2_s4,x2_s6);
                            break;
                    default :j22-=1;
                             cout<<" INVALID INPUT :"<<endl;
                             break;


                }

            }
                    }
                    w2_o=w2_o+1;
                    bow_set_func(bo2[w2],w2_r,w2_o,w2_w);
                    swap_main_func(x2,x2_r,x2_b,x2_s4,x2_s6,y2,y2_r,y2_b,y2_s4,y2_s6);
    }
    t2_truns=t2_truns+x2_r+y2_r+extras_2;
    int h22=max(x2,y2);
    bat_set_func(ba2[x2],x2_r,x2_b,x2_s4,x2_s6);
    bat_set_func(ba2[y2],y2_r,y2_b,y2_s4,y2_s6);
    if(t2_truns>=target)
    {
        cout<<"  \t\t\t\t*************     "<<m.team2_n<<"    WON     BY     "<<10-(t2_wickets)<<"        ***************"<<endl;
    }
    else
    {
        if(t1_truns==t2_truns)
        {
                cout<<"            \t\t\t ******     DRAW      *******"<<endl;
        }
        else
        {
            cout<<"  \t\t\t\t*************     "<<m.team1_n<<"    WON     BY     "<<t1_truns-t2_truns<<"      RUNS     ***************"<<endl;
        }

    }
    cout<<"\n\n\n"<<endl;
    cout<<setw(100)<<"SCORE BOARD\n\n\n"<<endl;
    cout<<setw(50)<<" 1 st INNINGS   \n\n "<<endl;
    cout<<"BATTING \tPLAYER NAME          R       B       4s      6s     \n\n"<<endl;
    for(int h1=1;h1<=h11;h1++)
    {
      cout<<"\t\t"<<ba1[h1]->p_fname<<" "<<ba1[h1]->p_lname<<"\t\t"<<ba1[h1]->get_p_runs()<<"\t\t"<<ba1[h1]->get_p_balls()<<"\t\t"<<ba1[h1]->get_p_s4()<<"\t\t"<<ba1[h1]->get_p_s6()<<"\n"<<endl;

    }
    cout<<"\n"<<endl;
    cout<<"BOWLING  \t BOWLER NAME        O       R       W       ECONOMY    \n\n"<<endl;
    for(int h2=1;h2<=5;h2++)
    {
        cout<<"\t\t"<<bo1[h2]->get_b_name()<<"\t\t"<<bo1[h2]->get_b_overs()<<"\t"<<bo1[h2]->get_b_runs()<<"\t"<<bo1[h2]->get_b_wickets()<<"\t"<<bo1[h2]->get_b_economy()<<"\n";

    }
    cout<<"\n\n"<<endl;
    cout<<setw(50)<<" 2  nd INNINGS   \n\n "<<endl;
    cout<<"BATTING\t PLAYER NAME          R       B       4s      6s     \n\n"<<endl;
    for(int h3=1;h3<=h22;h3++)
    {
    cout<<"\t\t"<<ba2[h3]->p_fname<<" "<<ba2[h3]->p_lname<<"\t\t"<<ba2[h3]->get_p_runs()<<"\t\t"<<ba2[h3]->get_p_balls()<<"\t\t"<<ba2[h3]->get_p_s4()<<"\t\t"<<ba2[h3]->get_p_s6()<<"\n"<<endl;

    }
    cout<<"\n"<<endl;
    cout<<"BOWLING  \t BOWLER NAME        O       R       W       ECONOMY    \n\n"<<endl;
    for(int h4=1;h4<=5;h4++)
    {
    cout<<"\t\t"<<bo2[h4]->get_b_name()<<"\t\t"<<bo2[h4]->get_b_overs()<<"\t"<<bo2[h4]->get_b_runs()<<"\t"<<bo2[h4]->get_b_wickets()<<"\t"<<bo2[h4]->get_b_economy()<<"\n"<<endl;
    }
    cout<<"\n\n";
    cout<<setw(80)<<"*****************************************************************************************************";

    return 0;
}


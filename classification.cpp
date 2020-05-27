#include<bits/stdc++.h>
using namespace std;

// A <= B
vector<pair<string,string> > type1;

//A and B <= C
vector<pair<pair<string,string>,string> > type2;

//A <= Exist B. C
vector<pair<string,pair<string,string> > > type3;

//Exist A.B <= C
vector<pair <pair<string,string>,string> > type4;
map<string,int> m;

vector<pair<string,string> > inf;



string T="all";

bool rule1(){
    bool changee=false;
    for(int i=0;i<type1.size();++i){
        for(int j=0;j<type1.size();++j){
            pair<string,string> p1=type1[i];
            pair<string,string> p2=type1[i];
            if(p1.second==p2.first){
                bool exist=false;
                for(int l=0;l<type1.size();++l){
                    if(p1.first==type1[l].first && p2.second==type1[l].second){
                        exist=true;
                        break;
                    }
                }
                if(!exist){

                        cout<<p1.first<<" "<<p2.second<<endl;
                        type1.push_back(make_pair(p1.first,p2.second));
                    changee=true;
                }
            }
        }
    }
    return changee;
}

bool rule2(){
    bool changee=false;
    for(int i=0;i<type1.size();++i){
        for(int j=0;j<type1.size();++j){
            pair<string,string> p1=type1[i];
            pair<string,string> p2=type1[j];
            if(p1.first!=p2.first) continue;
            for(int k=0;k<type2.size();++k){
                pair<pair<string,string>, string> p3=type2[k];
                if(p3.first.first==p1.second && p3.first.second==p2.second){
                    bool exist=false;

                    for(int l=0;l<type1.size();++l){
                    if(p1.first==type1[l].first && p3.second==type1[l].second){
                        exist=true;
                        break;
                    }
                }
                if(!exist){
                        cout<<p1.first<<" "<<p3.second<<endl;
                        type1.push_back(make_pair(p1.first,p3.second));
                    changee=true;
                }
                }
            }
        }
    }
    return changee;
}

bool rule3(){
    bool changee=false;
    for(int i=0;i<type1.size();++i){
        for(int j=0;j<type3.size();++j){
            for(int k=0;k<type4.size();++k){
                pair<string,string>  p1=type1[i];
                pair<string,pair<string,string>  > p3=type3[j];
                pair <pair<string,string>,string>  p4=type4[k];
                if(p3.second.first==p4.first.first && p1.second==p4.first.second && p1.first==p3.second.second){
                    //p3.first p4.second
                    bool exist=false;

                    for(int l=0;l<type1.size();++l){
                    if(p3.first==type1[l].first && p4.second==type1[l].second){
                        exist=true;
                        break;
                    }
                }

                if(!exist){
                        cout<<p3.first<<" "<<p4.second<<endl;
                        type1.push_back(make_pair(p3.first,p4.second));
                    changee=true;
                }
                }
            }
        }
    }
    return changee;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("1.inp","r",stdin);
    int n;
    cin>>n;
    m[T]=1;
    inf.push_back(make_pair(T,T));
    for(int i=1;i<=n;++i){
        int type;
        cin>>type;
        if(type==1){
            string s1,s2;
            cin>>s1>>s2;
            type1.push_back(make_pair(s1,s2));
            if(!m[s1]){
                m[s1]=1;
                inf.push_back(make_pair(s1,s1));
                inf.push_back(make_pair(s1,T));
            }
            if(!m[s2]){
                m[s2]=1;
                inf.push_back(make_pair(s2,s2));
                inf.push_back(make_pair(s2,T));
            }
        }
        else if(type==2){
            string s1,s2,s3;
            cin>>s1>>s2>>s3;
            type2.push_back(make_pair(make_pair(s1,s2),s3));
            if(!m[s1]){
                m[s1]=1;
                inf.push_back(make_pair(s1,s1));
                inf.push_back(make_pair(s1,T));
            }
            if(!m[s2]){
                m[s2]=1;
                inf.push_back(make_pair(s2,s2));
                inf.push_back(make_pair(s2,T));
            }
            if(!m[s3]){
                m[s3]=1;
                inf.push_back(make_pair(s3,s3));
                inf.push_back(make_pair(s3,T));
            }
        }
        else if(type==3){
            string s1,s2,s3;
            cin>>s1>>s3>>s2;
            if(!m[s1]){
                m[s1]=1;
                inf.push_back(make_pair(s1,s1));
                inf.push_back(make_pair(s1,T));
            }
            if(!m[s2]){
                m[s2]=1;
                inf.push_back(make_pair(s2,s2));
                inf.push_back(make_pair(s2,T));
            }
            type3.push_back(make_pair(s1,make_pair(s3,s2)));
        }
        else if(type==4){
            string s1,s2,s3;
            cin>>s3>>s1>>s2;
            if(!m[s1]){
                m[s1]=1;
                inf.push_back(make_pair(s1,s1));
                inf.push_back(make_pair(s1,T));
            }
            if(!m[s2]){
                m[s2]=1;
                inf.push_back(make_pair(s2,s2));
                inf.push_back(make_pair(s2,T));
            }
            type4.push_back(make_pair(make_pair(s3,s1),s2));
        }
    }
    for(int i=0;i<inf.size();++i){
        type1.push_back(inf[i]);
    }
   // for(int i=0;i<type1.size();++i) cout<<type1[i].first<<type1[i].second<<endl;

        while(true){
            bool change=false;
            if(rule1()) change=true;
            if(rule2()) change=true;
            if(rule3()) change=true;
            if(!change) break;
        }

}

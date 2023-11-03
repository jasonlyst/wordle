#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;



string answer() {

    ifstream answers;
    answers.open("wordle-answers-alphabetical.txt");

    string a;

    string ans[2315];
    int j = 0;

    while(getline(answers,a)) {
        ans[j] = a;
        ++j;
    }

    int *c;

    c = new int;

    srand(time(NULL));
    *c = rand()%2315;

    string correct_answer = ans[*c];
    answers.close();
    delete c;
    return correct_answer;
}




int main() {

    string a = answer();
    int t = 0;
    while(t<6) {

        cout<<"You are on attempt number "<<t+1<<". Type answer below."<<endl;
        cout<<endl;
        string ans;
        cin>>ans;
        char response[5];

        for(int i=0;i<5;i++) {

            bool T;

                for(int p=0;p<5;p++) {
                    
                    if(ans[i]==a[p]){
                        T = true;
                        break;
                    } else {
                        T = false;
                    }

                } 

                if(a[i]==ans[i]) {
                    response[i] = 'G';

                }
                else if(T && a[i]!=ans[i]) {
                    response[i] = 'Y';
                }
                else if(!T) {
                    response[i] = 'R';
                }



        }

        for(int k=0;k<5;k++) {
            cout<<response[k];
        }
        cout<<endl;
        
        char win[5];

        for(int v=0;v<5;v++) {
            win[v] = 'G';
        }

        int b = 0;


        for(int q; q<5; q++) {

            if(response[q] == win[q]) {
                b++;
            }

        }

        if(b==5) {
            cout<<"You win"<<endl;
            return 0;
        }
    

        t++;
    }



    cout<<endl;
    cout<<"You lost"<<endl;
    cout<<a;
    return 0;
}

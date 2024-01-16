#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//THIS IS MY FIRST OFFICIAL C++ PROGRAM!!!!


//The below function chooses a word that is the correct answer. It is a pointer so it can return an array. 
char* answer() {

    //Opens file. Answers is the file. 
    ifstream answers;
    answers.open("wordle-answers-alphabetical.txt");

    //Define dimensions of 2d character array of answers. 2315 possible answers with 5 possible letters for each. 
    int rows = 2315;
    int colunms = 5;

    //Creates matrix with a pointer pointing to another array of pointers, which then point to the individual character array answers.
    char** ans = new char*[rows];
    //Creates an array for each answer.
    char * a = new char[colunms];

    //Adds the correct number of colunms to the 2d array. 
    for(int g=0;g<rows;g++) {
        ans[g] = new char[colunms];
    }

    //Retrieves information from the file. 
    int j = 0;
    while(answers.getline(a,sizeof(a))) {
        for(int t=0;t<5;t++) {
            ans[j][t] = a[t];
        }
        j++;
    }

    //Random index to choose correct word. IDK why I chose it to be dynamically allocated. 

    int *c;


    c = new int;

    //Chooses random number. 
    srand(time(NULL));
    *c = rand()%2315;

    //allocates space for correct answer. 
    char* correct_answer = new char[5];

    //assigns correct answer characters to character array. 
    for(int b=0;b<5;b++) {
        correct_answer[b] = ans[*c][b];
    }
    answers.close();

    //memory clearnance and return.
    delete c;
    for(int i=0;i<5;i++) {
        delete[] ans[i];
    }
    delete[] ans, a;
    return correct_answer;

}

//function that checks yellow letters to check if the yellow letter has been used beforehand. Takes pointer argument because the yellow is defined as a pointer.

bool checkIf(char *l,char i) {
    int n = strlen(l);
    for(int j=0; j<n; j++) {
        if(l[j]==i) {
            return true;
        }
    }
    return false;

}




int main() {

    // Pointer to character so it can retrieve the character array pointer from the answer() function. 
    char *a;
    // Assigns a with the character answer pointer. 
    a = answer();

    //Iteration variable for attempts
    int t = 0;

    //Iterates through the process of checking answers until out of attempts. 
    while(t<6) {

        //Input
        cout<<"You are on attempt number "<<t+1<<". Type answer below."<<endl;
        cout<<endl;

        //output
        char ans[5];
        cin>>ans;
        
        //Array corresponding to the correctness of the input characters. 
        char *response = new char[5];

        //Variable defining number of correct letters. 
        int b = 0;

        //Character list of yellowed letters. Allocated because it is changed throughout iteraitons. 
        char * yellow = new char[5];
        
        //Array index for yellow array. 
        int y = 0;

        //Variables to fix yellow before green bug.
        //points to location of yellow letter. 
        char *ptr = new char;

        //Iterates through word guess. 
        for(int i=0;i<5;i++) {

            //Determines a yellow letter. 
            bool T;


                //Checks for a yellow letter. 
                for(int p=0;p<5;p++) {
                    if(ans[i]==a[p]){
                        T = true;
                        break;
                    } else {
                        T = false;
                    }

                } 

                //Correct letter, Yellow letter, red letter.
                if(a[i]==ans[i]) {
                    response[i] = 'G';
                    b++;
                    if(checkIf(yellow,ans[i])) {
                        *ptr = 'R';
                    }

                }
                else if(T && a[i]!=ans[i]) {
                    
                    bool c = checkIf(yellow,ans[i]);
                    if(c==false) {
                        yellow[y] = ans[i];
                        response[i] = 'Y';
                        ptr = &response[i];
                        y++;
                        
                    } else {
                        response[i] = 'R';
                    }
                }
                else if(!T) {
                    response[i] = 'R';
                    yellow[y] = ans[i];
                    y++;
                }



        }

        //Gives the correctness of each inputed character. 
        for(int k=0;k<5;k++) {
            cout<<response[k];
        }
        cout<<endl;

        if(b==5) {
            cout<<"You Win!!"<<endl;
            delete[] a;
            return 0; 
        }
        
        delete[] response, ptr;
        delete[] yellow;
        t++;
    }

    cout<<endl;
    cout<<"You lose."<<endl;
    
    cout<<"Correct answer is: ";
    for(int l=0;l<5;l++) {
        cout<<a[l];
    }

    delete[] a; 
    return 0;
}

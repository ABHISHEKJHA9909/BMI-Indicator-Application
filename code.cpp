#include<iostream>
#include<vector>
using namespace std;


/*this fucntion will work as UI to show current position of the game*/
void print_box(char a,char b,char c,char i,char j,char k,char x,char y,char z){
	cout<<"+---+---+---+"<<endl;
	cout<<"| "<<a<<' '<<"| "<<b<<' '<<"| "<<c<<" |";
	cout<<endl;
	cout<<"+---+---+---+"<<endl;
	cout<<"| "<<i<<' '<<"| "<<j<<' '<<"| "<<k<<" |";
	cout<<endl;
	cout<<"+---+---+---+"<<endl;
	cout<<"| "<<x<<' '<<"| "<<y<<' '<<"| "<<z<<" |";
	cout<<endl;
	cout<<"+---+---+---+"<<endl;
}

/*this fucntion will take user input for position they want to mark and
 * check if the position is previouly occuppied*/
void input(vector<char> &attemped_positions,char &player_input,int player_no){
		while(true){
			cout<<"player"<<player_no<<':';
			cin>>player_input;
			bool flag=0;
			for(int input:attemped_positions){
				if(input==player_input){
					cout<<"position already filled"<<endl;
					flag=1;
					break;
				}
			}
			if(flag)continue;
			attemped_positions.push_back(player_input);
			break;
		}
}


/*after getting suitable place to mark this fucntion will change variable
 * to X or O based on user 1 and user 2*/
void variable_maping(char player_input,char XO,char &a,char &b,char &c,char &i,char &j,char &k,char &x,char &y,char &z){
	if(player_input=='1')a=XO;
	if(player_input=='2')b=XO;
	if(player_input=='3')c=XO;
	if(player_input=='4')i=XO;
	if(player_input=='5')j=XO;
	if(player_input=='6')k=XO;
	if(player_input=='7')x=XO;
	if(player_input=='8')y=XO;
	if(player_input=='9')z=XO;
	print_box(a,b,c,i,j,k,x,y,z);
	cout<<endl<<endl;
}



/*this play function contain everyting(containers variabel and rules) used
 * to play a round.  */
void play(){
	cout<<"player1:X"<<endl<<"player2:O"<<endl;
	char a='1',b='2',c='3',i='4',j='5',k='6',x='7',y='8',z='9';			//variables for each position so that we can change it when user enter a positon
	print_box(a,b,c,i,j,k,x,y,z);										//This is very first time when our grid is shown
	cout<<endl<<endl;

	char player1_input,player2_input;									//variable to take user input to select the position they want to mark
	vector<char>attemped_positions={};

	while(true){
		if((a==b&&b==c)||(i==j&&j==k)||(x==y&&y==z)||(a==i&&i==x)||(b==j&&j==y)||(c==k&&k==z)||(a==j&&j==z)||(c==j&&j==x)){
			cout<<"player 2 win";
			break;
		}
		input(attemped_positions,player1_input,1);
		variable_maping(player1_input,'X',a,b,c,i,j,k,x,y,z);


		if((a==b&&b==c)||(i==j&&j==k)||(x==y&&y==z)||(a==i&&i==x)||(b==j&&j==y)||(c==k&&k==z)||(a==j&&j==z)||(c==j&&j==x)){
			cout<<"Player 1 win";
			break;
		}
		if(attemped_positions.size()==9){
			cout<<"Draw"<<endl;
			break;
		}
		input(attemped_positions,player2_input,2);
		variable_maping(player2_input,'O',a,b,c,i,j,k,x,y,z);
	}
	cout<<endl;
}

int main(){
	play();
	char play_or_not='y';
	while(true){
		cout<<endl;
		cout<<"want to play more(y/n):";
		cin>>play_or_not;
		if(play_or_not=='y'||play_or_not=='Y')
			play();
		else if(play_or_not=='n'||play_or_not=='N')
			return 0;
		else
			cout<<"Invalid input"<<endl<<endl;
	}
}

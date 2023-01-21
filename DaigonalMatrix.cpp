//Program 13:
// 1) Diagonal Matrix using one-dimensional array.
#include<iostream>
using namespace std;

class matrix{
    int size;
    int* arr;
    public: 
        matrix(int n){
            size = n;
            arr = new int[n];
        }

        void input(){
            cout << "Enter values: ";
            int value;
             for(int i=0; i<size; i++){
                for(int j=0; j< size; j++){
                    cin >> value;
                    store(i,j,value);
                }
            }
        }
        void store (int i, int j, int val){
            if(val!=0){
            int index;
            if(i==j){
                index= i;
                arr[index] = val;
            }
            }
            // else 
            // cout << "Error enter valid value" << endl;
        }

        int ret(int i, int j){
            int index;
            if(i==j){
                index= i;
                return arr[index];
            }
            return 0;
        }

        void print(){
            for(int i=0; i<size; i++){
                for (int j=0; j< size; j++){
                    cout << ret(i,j) << " ";
                }
                cout << endl;
            }
        }
        

};

int main(){
    cout << "Enter the size of matrix (eg 3 x 3): ";
    int size;
    cin >> size;
    matrix m(size);
    cout << "1. input value.\n";
    cout << "2. retrieve a value\n";
    cout << "3. print matrix\n";
    cout << "4. Exit\n";
    bool flag = false;
	while(!flag){
		int select;
		cout<<"Make choice: " << endl;
		cin >> select;
		switch(select){
	    case 1:
	        m.input();
	        break;
	    case 2:
	        cout << "enter the row: ";
	        int row;
	        cin >> row;
	        cout << "Enter the column: ";
	        int col;
	        cin >> col;
	        cout << "Element: " << m.ret(row,col) << endl;
	        break;
	    case 3: 
			cout << "Your matrix: " << endl;
	        m.print();
	        break;
	    case 4:
        flag = true;
		break;

	    default:
	        cout << "invalid Choice" << endl;
	        break;
	    }
    }
    return 0;
}





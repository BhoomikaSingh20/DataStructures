//Program 13:
// 3) Upper Triangular Matrix using one-dimensional array.

#include<iostream>
using namespace std;

class matrix{
    int size;
    int* arr;
    public: 
        matrix(int n){
            size = (n*(n+1))/2;
            arr = new int[size];
        }

        void input(int n){
            cout << "Enter values: ";
            int value;
             for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout << "enter " << i << "," << j << " value: ";
                    cin >> value;
                    store(i,j,value);
                }
            }
        }
        void store (int i, int j, int val){
            int index;
            if(i<=j ){
                if(val!=0){
                index= j*(j+1)/2 + i;
                arr[index] = val;
                }
                 else 
                cout << "Error invalid value" << endl;
            }
           
        }

        int ret(int i, int j){
            int index;
            if(i<=j){
                index= j*(j+1)/2 + i;
                return arr[index];
            }
            return 0;
        }

        void print(int n){
            for(int i=0; i<n; i++){
                for (int j=0; j< n; j++){
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
    cout << "4. exit\n";
    bool flag = false;
	while(!flag){
		int select;
		cout<<"Make choice: " << endl;
	cin >> select;
	switch(select){
    case 1:
        m.input(size);
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
    case 3: cout << "Your matrix: " << endl;
            m.print(size);
            break;
    case 4:
            flag = true;
			break;
    default:
            cout << "Invalid choice" << endl;
        break;
    }
    }
    return 0;
}


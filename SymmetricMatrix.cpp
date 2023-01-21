//Program 13:
// 4) Symmetric Matrix using one-dimensional array.

#include<iostream>
using namespace std;

class matrix{
    int r;      //size of the matrix (eg if 3 x 3 then r is 3)
    int size;
    int* arr;
    public: 
        matrix(int n){
            r = n;
            size = (n*(n+1))/2;
            arr = new int[size];
        }

        void swap(int &i,int &j){
            int temp = j;
            j = i;
            i = temp;
        }

        void input(){
            cout << "Enter values: ";
            int value;
             for(int i=0; i<r; i++){
                for(int j=0; j<r; j++){
                    cout << "enter " << i << "," << j << " value: ";
                    cin >> value;
                    store(i,j,value);
                }
            }
        }
        void store (int i, int j, int val){
            if(i<0 || j<0 || i>r || j>r){
		        cout<<"\nInvalid matrix index\n";
		        return;
            }
            if(i<j){
		        swap(i,j);
	        }
	        arr[(i*(i-1)/2)+(j-1)]=val;
           
        }

        int ret(int i, int j){
           if(i<0 || j<0 || i>r || j>r){
		    cout<<"\nInvalid matrix index\n";
		    return -1;
	        }
	        if(i<j)
                swap(i,j);
	        return arr[(i*(i-1)/2)+(j-1)];
        }

        void print(){
            for(int i=0; i<r; i++){
                for (int j=0; j< r; j++){
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
    case 3: cout << "Your matrix: " << endl;
            m.print();
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

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    int num = 1;
    for(int i = 0 ; i < n ; i++)
    {
        vector<int> arr(i+1);
     
            for(int j = 0 ; j < i+1 ; j++)
            {
                arr[j]=num++;
            }

    
        if(i %2 ==0)
        {
            for(int j = i ; j >= 0; j--)
            {
                cout<<arr[j]<<" ";
            }
            
        }
        else{
            for(int j = 0 ; j <=i ; j++)
            {
                cout<<arr[j]<<" ";
            }    
        }
        cout<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    int num = 1;

    for (int i = 0; i < n; i++) {
        int row_size = i + 1;

        if (i % 2 == 0) {
            
            int end = num + row_size - 1;
            for (int j = end; j >= num; j--) {
                cout << j << " ";
            }
        } else {
           
            for (int j = 0; j < row_size; j++) {
                cout << num + j << " ";
            }
        }

        num += row_size;
        cout << endl;
    }

    return 0;
}


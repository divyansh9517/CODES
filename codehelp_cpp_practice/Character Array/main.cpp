#include<bits/stdc++.h>
using namespace std;

int getLength(char arr[])
{
    int count = 0;
    int index = 0;
    while(arr[index] != '\0')
    {
        count++;
        index++;
    }
    return count;
}

void concatArr(char brr[],char crr[])
{
    int aIndex = getLength(brr);
    int bIndex = 0;
    
    while(crr[bIndex] != '\0')
    {
        brr[aIndex] = crr[bIndex];
        aIndex++;
        bIndex++;
    }
    // end a string with null character
    brr[aIndex] = '\0';

}

void copyArr(char a[],char newArr[])
{
    int aIndex = 0;
    int bIndex = 0;
    while(a[aIndex] != '\0')
    {
        // start copying
        newArr[bIndex] = a[aIndex];
        aIndex++;
        bIndex++;
    }
    newArr[bIndex] = '\0';
}


bool compare(char a[],char b[])
{
    int alen = getLength(a);
    int blen = getLength(b);

    if(alen != blen)
    {
        return false;
    }

    int i =0;
    int j = 0;

    while(i <= alen)
    {
        if(a[i] != b[j])
        {
            return false;
        }
        else{
            i++;
            j++;
        }
    }
    return true;

}
int main()
{
    //char arr[10]="divyansh";

    // mughy character array ko terminate krny ke liye null character add  krna hoga

    // char arr[4];

    // arr[0] = 'a';
    // arr[1] = 'b';
    // arr[2] = '\0'; // this is a null character

    // int nu = arr[2]; 
    // //the ascii value of null character is 0

    // cout<<nu<<endl;

    // cout<<arr[5]<<endl;

    int arr[10];
    cout<<arr<<endl; // this line shows base address of the array

    char brr[20]="divyansh";//  in character array it will print the value of the array
    cout<<brr<<endl;

    

    //common operation

    // 1.find length   "divyansh" length = 8
    cout<<getLength(brr);

    // 2. concatenation do array ko jod do 
    char crr[20] ="saxena";
    concatArr(brr,crr);

    cout<<"Printing a : " << brr<<endl;

    // 3. copying 

    char a[10]="divyansh";
   

    char newArr[10];
    copyArr(a,newArr);
    cout<<newArr<<endl;

    // 4. comparing array
    char b[10]="divy";
    cout<<compare(a,b);


    // 4 library function

    char actual[]= "babbar";
    char ans[100];

    strcpy(ans,actual);
    cout<<ans<<endl;

    cout<<strlen(actual)<<endl;

    if(strcmp(actual,ans)==0)
    {
        cout<<"both array are same"<<endl;
    }
    else{
        cout<<"different"<<endl;
    }

    // strcat() -> str concatenate

}
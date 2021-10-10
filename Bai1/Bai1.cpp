#include<bits/stdc++.h>

using namespace std;

void input(long *&a, int &n){
	//mo file input.txt de doc
	ifstream fin("INPUT.TXT");
	//Doc dong dau vao bien n
	fin>>n;
	//cap phat bo nho cho a
	a=new long[n];
	// doc dong thu 2 vao mang a
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	fin.close();
}
void display(long *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"";
	}
	cout<<endl;
}
long algol(long *a, int n, int &left,int &right){
	long max = a[0];
	for (int i = 0; i < n; i ++){
		for (int j = i; j < n; j ++){
			long s = 0;
			for (int k = i; k <= j; k ++){
				s = s + a[k];
			}
			if (max<s){
				max=s;
				left=i;
				right=j;
			}
		}
	}
return max ;
}
void output(long *a, int left, int right){
	//tao file output.txt de ghi du lieu
	ofstream fout("OUTPUT.TXT");
	fout<<left<<" "<<right<<endl;
	for(int i=left; i<= right; i++){
		fout<<a[i]<<" ";
	}
	fout.close();
}

int main(){
	long *a;
	int n;
	input(a,n);
	cout<<"Day s:";
	display(a,n);
	int left, right;
	long max=algol(a,n,left,right);
	cout<<"day con tong lon nhat la s("<<left+1<<","<<right+1<<")={";
	for(int i=left;i<=right; i++){
		cout<<a[i]<<"";
	}
	cout<<"}"<<endl;
	cout<<"Tong cua day con la"<<max<<endl;
	output(a, left, right);
}

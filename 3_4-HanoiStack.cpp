// use stack to solve hanoi problems;

#include <iostream>
#include <stack>
using namespace std;


// use recursive method to sovle the hanoi tower problem

void hanoi(int n, char sta, char bri, char dst)
{
	if(n == 1)
		cout<<"Move disk "<< n <<" from "<< sta <<" to "<< dst <<endl;
	else
		{
			hanoi( n-1, sta, dst, bri);
			cout<<"Move disk "<< n <<" from "<< sta <<" to "<< dst <<endl;
			hanoi( n-1, bri, sta, dst);
		}
}

struct op{
    int begin, end;
    char sta, bri, dst;
    op(){
        
    }
    op(int pbegin, int pend, int psta, int pbri, int pdst):begin(pbegin), end(pend), sta(psta), bri(pbri), dst(pdst){
        
    }
};
void hanoi(int n, char sta, char bri, char dst){
    stack<op> st;
    op tmp;
    st.push(op(1, n, sta, bri, dst));
    while(!st.empty()){
        tmp = st.top();
        st.pop();
        if(tmp.begin != tmp.end){
            st.push(op(tmp.begin, tmp.end-1, tmp.bri, tmp.sta, tmp.dst));
            st.push(op(tmp.end, tmp.end, tmp.sta, tmp.bri, tmp.dst));
            st.push(op(tmp.begin, tmp.end-1, tmp.sta, tmp.dst, tmp.bri));
        }
        else{
            cout<<"Move disk "<<tmp.begin<<" from "<<tmp.sta<<" to "<<tmp.dst<<endl;
        }
        
    }
}
int main(){
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
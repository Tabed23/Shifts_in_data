#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Soultion
{
private:
    int K;
public:
    
    int how_many_shifts(vector<int>vs)
    {
        int start =0;
        int end=  vs.size()-1;
        int middle;
        while (start <=end)
        {   middle = start+(end - start)/ 2;
            if(vs[middle]<= vs[middle+1] && vs[middle]<=  vs[middle-1])
            {
                this->K =middle;
                break;
            }
            else if(vs[middle]<=vs[end])
            {
                end = middle-1;
            }
            else if(vs[middle]>= vs[start])
            {
                start = middle +1;
            }
        }
        return this->K;
    }


    void undo_shifts(vector<int>&vs)
    {
        reverse(vs.begin(), vs.begin()+this->K);
        reverse(vs.begin()+this->K, vs.end());
    }
};


void print(vector<int>);
int main()
{
    vector<int>VS ={10,20,30 ,40,50,60,70,80,1 ,2 ,3 ,4 ,5};
    print(VS);
    Soultion s;
    cout << "total shift := " << s.how_many_shifts(VS)<<endl;
    s.undo_shifts(VS);
    print(VS);

}
void print(vector<int> v)
{
    for(auto x: v)
    {
        cout << x << " ";
    }
    cout <<endl;
}
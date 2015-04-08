#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class nodes{
public:
    int id;
    int ext;
    nodes **ptr;
    int c;
    nodes()
    {
        id=0;
        ext=0;

        //ptr=new nodes*[x];
    }
    nodes(int i, int n,int w)
    {
        id=i;
        ext=w;
        ptr=new nodes*[n];
        c=0;
    }

 };

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    nodes *a=new nodes [N];
    for(int i=0;i<N;i++)
    {
        a[i]= nodes(i,N,0);
    }

    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        a[N1].ptr[((a[N1].c)++)]=&a[N2];
        a[N2].ptr[((a[N2].c)++)]=&a[N1];

    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        a[EI].ext=1;
    }
    /*for(int i=0;i<N;i++)                 for checking the graph
    { 
        cout<<a[i].id<<"\n";
        cout<<"connected to-\n";
        for(int j=0;j<a[i].c;j++)
        {
            cout<<(a[i].ptr[j])->id<<" ";
        }
        cout<<"\n exit="<<a[i].ext<<"\n";
    }*/
    nodes *start=new nodes();
    // game loop
    while (1) {
        int out=0;
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        for(int i=0;i<a[SI].c;i++)
        {
            if((a[SI]).ptr[i]!=NULL && (a[SI].ptr[i])->ext==1)
            {
                int z=SI;
                int b= ((a[SI]).ptr[(i)])->id;
                cout <<z<<" "<<b << endl;
                out=1;
                a[SI].ptr[i]=NULL;
                for(int j=0;i<a[b].c;j++)
                {
                    if(a[b].ptr[j]!=NULL && (a[b].ptr[j])->id==z)
                    {
                        a[b].ptr[j]=NULL;
                        break;
                    }
                }
            }
        }
        if(out==0)
        {
            int r=0;
            while(1)
            {
                if(a[SI].ptr[r]!=NULL)
                {
                    int z=SI;
                    int b= (a[SI].ptr[r])->id;
                    cout <<z<<" "<<b << endl;
                    out=1;
                    a[SI].ptr[r]=NULL;
                    for(int j=0;j<a[b].c;j++)
                    {
                        if(a[b].ptr[j]!=NULL && (a[b].ptr[j])->id==z)
                        {
                            a[b].ptr[j]=NULL;
                            break;
                        }
                    }
                    break;
                }
                r++;
            }
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        //cout << "1 2" << endl; // Example: 0 1 are the indices of the nodes you wish to sever the link between
    }
}
#include<fstream>
#include<vector>
#include<list>

int main()
{
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    
    int numOfEdges(0);
    int numOfNodes(0);

    in>>numOfNodes>>numOfEdges;

    std::vector<std::list<int>> arr(numOfNodes);

    for(int i(0);i<numOfEdges;++i)
    {
        int nodeBegin(0);
        int nodeEnd(0);

        in>>nodeBegin>>nodeEnd;

        arr[nodeBegin-1].push_back(nodeEnd);
        arr[nodeEnd-1].push_back(nodeBegin);

    }

    for(int i(0);i<numOfNodes;++i)
    {
        out<<arr[i].size()<<" ";
        for( auto j: arr[i])
        {
            out<<j<<" ";
        }
        out<<"\n";
    }

    in.close();
    out.close();
}

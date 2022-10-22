#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int getElementSize(string str)
{
    istringstream nums(str);
    int in, ct = 0;

    while (nums >> in && in != -1)
    {
        ct++;
    }

    return ct;

}

int getElement(string str, int index)
{
    istringstream nums(str);

    int in, ct = 0;

    while (nums >> in && in != -1)
    {
        if (ct == index)
        {
            return in;
        }

        ct++;
    }

}

void push2Q(queue<int> &q, string str)
{
    int size = getElementSize(str);

    if (size == 2)
    {
        //two elements
        q.push(getElement(str, 0));
        q.push(getElement(str, 1));

    }

    if (size == 3)
    {
        //three elements
        q.push(getElement(str, 0));
        //cout << q.back() << endl;
        q.push(getElement(str, 1));
        //cout << q.back() << endl;
        q.push(getElement(str, 0));
        //cout << q.back() << endl;
        q.push(getElement(str, 2));
        //cout << q.back() << endl;
    }

    if (size == 4)
    {
        //three elements
        q.push(getElement(str, 0));
        //cout << q.back() << endl;
        q.push(getElement(str, 1));
        //cout << q.back() << endl;
        q.push(getElement(str, 0));
        //cout << q.back() << endl;
        q.push(getElement(str, 2));
        //cout << q.back() << endl;
        q.push(getElement(str, 0));

        q.push(getElement(str, 3));
    }
}

void conditionalPush(vector<int> pred, queue<int> &q, int frontElement, int nxtElement)
{

    //push front element only if nxtElement isnt already visited
    if (pred[nxtElement] == -1)
    {
        q.push(frontElement);
        q.push(nxtElement);
    }

}

vector<int> solveMaze(vector<string> arr, int start, int end)
{
    vector <int> pred(arr.size()+ 1, -1);
    queue<int> q;
    int loc = 0, frw = start, size;
    string str;
    int line = 2;

    int frontElement, nextElement, element;

    push2Q(q, arr[start - 1]);

    //pred[frw] = loc   //     {-1, -1, -1, -1, -1, -1, 0}

    //cout << q.front() << " " << q.back() << endl;
    //q = {6, 5}
    //pred = {-1, -1, -1, -1, -1, -1, -1}

    while (!q.empty() && pred[loc] != end)
    {
        //change location & pop elements off the queue
        loc = q.front();    //6
        q.pop();
        frw = q.front();    //5
        q.pop();

        //update my pred
        pred[frw] = loc;    //{-1, -1, 1, -1, -1, 6, 0}

        //get the str
        for (int j = 0; j < arr.size(); j++)
        {
            if(getElement(arr[j], 0) == frw)
            {
                str = arr[j];
                break;
            }
        }

        size = getElementSize(str);

        // size = 1.

        if (size == 2)
        {
            frontElement = getElement(str, 0);
            nextElement  = getElement(str, 1);
            conditionalPush(pred, q, frontElement, nextElement);
        }

        else if (size == 3)
        {
            //three elements
            frontElement = getElement(str, 0);
            nextElement  = getElement(str, 1);
            conditionalPush(pred, q, frontElement, nextElement);
            frontElement = getElement(str, 0);
            nextElement  = getElement(str, 2);
            conditionalPush(pred, q, frontElement, nextElement);
        }

        else
        {
            //four elements
            frontElement = getElement(str, 0);
            nextElement  = getElement(str, 1);
            conditionalPush(pred, q, frontElement, nextElement);
            frontElement = getElement(str, 0);
            nextElement  = getElement(str, 2);
            conditionalPush(pred, q, frontElement, nextElement);
            frontElement = getElement(str, 0);
            nextElement  = getElement(str, 3);
            conditionalPush(pred, q, frontElement, nextElement);

        }
    }

    return pred;
}

int main()
{
    string str;
    vector<string> vertices;
    vector <int> soln;
    stack<int> elements;
    int entry, exit, cost = 0;
    int size = 0;

    ifstream fin, fin1;

    fin1.open("maze4.txt");
    fin1 >> exit >> entry;
    getline(fin1, str);
    while (getline(fin1, str))
    {
        size++;
    }

    fin.open("maze4.txt");

    fin >> entry >> exit;
    //fin >> exit >> entry;
    getline(fin, str);
    for(int i = 0; i < size; i++)
    {
        getline(fin, str);
        vertices.push_back(str);
    }

    fin.clear();
    fin.close();
    fin1.clear();
    fin1.close();

    soln = solveMaze(vertices, entry, exit);

    /*
     * Use a for loop to calculate where we came from at exit
     */


    //push the end into the stack first

    elements.push(exit);

    while (elements.top() != entry)
    {
        for (int j = 0; j < soln.size(); j++)
        {
            if (j == elements.top())
            {
                elements.push(soln[j]);
                break;
            }

        }
    }

    //output stuff
    cout << "Start -> ";
    while (!elements.empty())
    {
        cout << elements.top() << " -> ";
        elements.pop();
        cost++;
    }

    cost++;     //moving to exit
    cout << "Exit" << endl;
    cout << "Total Cost: " << cost << endl;

    return 0;
}

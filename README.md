# BST
 Binary Search Tree

1.!!!!!Important:
Please output the answer after all input is completed， 
Otherwise, the system will not recognize the output.
You can use my inputoutput function example:

void inputoutput()
{
    struct node* root = NULL;
    int n;
    cin>>n;
    queue<string> ops;
    queue<string> words;
    queue<int> depths;
    string op;
    string word;
    int dp;
    // input
     for(int i; i<n; i++)
    {
        string op;
        cin>>op;
        ops.push(op);
        if(op=="+")
        {
            cin>>word;
            words.push(word);
        }
        else if(op=="-")
        {
            cin>>word;
            words.push(word);
        }
        else if(op=="depth")
        {
            cin>>dp;
            depths.push(dp);
        }
        else if(op=="leaf")
        {
            ;
        }
    }

    // output
    while (!ops.empty())
    {
        op = ops.front();
        if(op=="+")
        {

            word = words.front();
	    // insert node
            ......
            words.pop();
        }
        else if(op=="-")
        {
            word = words.front();
            // delete node
	    ......
            words.pop();
        }
        else if(op=="depth")
        {
            dp = depths.front();
            // output all nodes in depth-th layer
            ......
            depths.pop();
        }
        else if(op=="leaf")
        {
            // output all leaf node
            ......
        }
        ops.pop();
    }
}

2.####################################################################

Input:
13
+ phone 
+ banana 
- cola 
+ chip 
leaf 
+ pizza 
+ soccer 
- phone 
depth 3 
+ machine 
depth 2 
- pizza 
leaf 

Output:
chip 
soccer 
banana pizza 
banana soccer 
'\n'

######################################################################
In this assignment, our output has a newline '\n'.
That means when we output the result, we need to output like:
cout<<"C"<<endl;

If I show '\b' in later assignments,
That means blank space:
cout<<" "; or cin>>" ";

Please using the example_data to check your answer is right or not 
before you upload the code.
######################################################################

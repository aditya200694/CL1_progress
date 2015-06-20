//============================================================================
// Name        : Graph.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * first line of input file contains a integer representing number of nodes
 * second line contains single integer representing threshold value
 * third line contains single integer L i.e. number of links
 * next L lines contains three space saperated integer i,j and d where
 * i and j is node number and d is disstance between them.
 *
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

class node {
public:

    int node_num, dist;
    node *next;
    node(int n, int d) {
        this->node_num = n;
        this->dist = d;
        next=NULL;
    }
};


void insert_node(node *graph_list[],int num,node * p){

    if(graph_list[num]==NULL){
        graph_list[num]=p;
        return;
    }
    node *temp=graph_list[num];

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;

}

int get_max_links(int nodes) {
    return (nodes * (nodes - 1)) >> 1;
}

int main() {

    string str;
    int num_nodes, num_links, max_links, threshold;
    fstream myfile;
    myfile.open("input.txt");

    if (!myfile.is_open()) {
        cout << "File not found" << endl;
        exit(1);
    }

    myfile >> str;
    num_nodes = atoi(str.c_str());

    max_links = get_max_links(num_nodes);

    myfile >> str;
    threshold = atoi(str.c_str());

    myfile >> str;
    num_links = atoi(str.c_str());

    ((num_links * 100) / (float) max_links) >= threshold ?
            cout << "matrix" : cout << "list";
//MATRIX
    /*
     int graph[num_nodes][num_nodes];
     //init to zero
     for(int i =0;i<num_nodes;i++)
     for(int j=0;j<num_nodes;j++){
     graph[i][j]=0;
     }
     string stemp;
     int source,dest,dist;
     for(int i=0;i<num_links;i++){
     myfile>>stemp;
     source=atoi(stemp.c_str());
     myfile>>stemp;
     dest=atoi(stemp.c_str());
     myfile>>stemp;
     dist=atoi(stemp.c_str());
     --source;
     --dest;
     graph[source][dest]=dist;
     graph[dest][source]=dist;
     }
     //printing data of matrix
     for(int i =0;i<num_nodes;i++)
     for(int j=0;j<num_nodes;j++){
     cout<<graph[i][j]<<endl;
     }
     */
//LIST
    node *graph_list[num_nodes];
    //init to null;
    for(int i=0;i<num_nodes;i++){
        graph_list[i]=NULL;
    }
    string stemp;
    int source, dest, dist;
    for (int i = 0; i < num_links; i++) {
        myfile >> stemp;
        source = atoi(stemp.c_str());
        myfile >> stemp;
        dest = atoi(stemp.c_str());
        myfile >> stemp;
        dist = atoi(stemp.c_str());

        node *p=new node(dest,dist);
        node *q=new node(source,dist);
        --source;
                --dest;
        insert_node(graph_list,source,p);
        insert_node(graph_list,dest,q);

    }

    //printing list
    for(int i=0;i<num_nodes;i++){
        cout<<i+1;
        node * temp=graph_list[i];//cout<<" "<<temp->node_num;
        while(temp!=NULL){
            cout<<" "<<temp->node_num;
            temp=temp->next;
        }
        cout<<endl;
    }

    return 0;
}

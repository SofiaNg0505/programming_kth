%% main
clc
clear all
global list
list = load('list.txt');
left=1;
right=length(list);
quicksort(left,right);
list
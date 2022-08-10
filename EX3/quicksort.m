%%% quicksort
function quicksort(left,right) 
global list
if (right > left)
    i = partition(left,right); % choose Pivot element
    i
    quicksort(left,i-1); % sort the left side of the Pivot
    quicksort(i+1,right); % sort the right side of the Pivot
end % if 
end % quicksort
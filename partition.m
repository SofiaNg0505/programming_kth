function pos_pivot = partition(left, right)
global list
i= round((left + right)/2); % step 1
fprintf('Starting conditions of partition')
left_counter = left
right_counter = right -1
pivot= list(i); % pivot middle element of array
lista = list(left:right)
position_of_pivot = i
fprintf('Change pivot position with last element');
[list(right), list(i)] = deal(list(i), list(right)); % step 2
lista = list(left:right)
left_counter
right_counter
position_of_pivot = right

while   right_counter - left_counter >= 1 % step 6
    left_index = [];
    right_index = [];
    while or(isempty(left_index),isempty(right_index)) && right_counter - left_counter >= 1 % while loop that breaks if either counter too close or both have found
        if isempty(left_index) % step 3: if left has not found yet
            if list(left_counter) > pivot % check condition in left_index
                left_index = left_counter; % if holds save position
                fprintf('Left counter found a bigger number than pivot')
                lista = list(left:right)
                left_counter
                right_counter
                position_of_pivot = right
            else
                left_counter = left_counter + 1; % otherwise go one further to the right
            end
        end
        if isempty(right_index) % step 4: if right has not found yet
            if list(right_counter) < pivot % check condition
                right_index = right_counter; % if holds save position in right_index
                fprintf('Right counter found a smaller number than pivot')
                lista = list(left:right)
                left_counter
                right_counter
                position_of_pivot = right
            else
                right_counter = right_counter - 1; % otherwise go one further to the left
            end
        end
    end % inner while loop
    % if difference of counters is 1
    if right_counter - left_counter == 1 %%
        left_counter = right_counter;
        if isempty(left_index) % if left has not found yet
            if list(left_counter) > pivot % check condition
                left_index = left_counter; % if holds save position in left_index
                fprintf('Left counter found a bigger number than pivot')
                lista = list(left:right)
                left_counter
                right_counter
                position_of_pivot = right
            end
        end
    end
    if not(isempty(left_index)) && not(isempty(right_index)) && left_index ~= right_index % step 5
        fprintf('Swop elements at position left_counter and right_counter');
        [list(right_index),list(left_index)]=deal(list(left_index),list(right_index));
        lista = list(left:right)
        left_counter
        right_counter
        position_of_pivot = right
    end % if
end % outer while

%% step 7
fprintf('Compare element at left_counter (=right_counter) with pivot \n');
if list(left_counter) > list(right) % compare counter positions with pivot
    fprintf('Element at counter > pivot \n => change positions of these elements');
    [list(right), list(left_counter)]= deal(list(left_counter), list(right));
    lista = list(left:right)
    left_counter
    right_counter
    position_of_pivot = left_counter
elseif list(left_counter) < list(right)
    fprintf('Element at counter < pivot \n => move element at counter +1 step and change positions of these elements');
    left_counter = left_counter + 1;
    right_counter = right_counter + 1;
    [list(right), list(left_counter)]= deal(list(left_counter), list(right));
    lista = list(left:right)
    left_counter
    right_counter
    position_of_pivot = left_counter
end
pos_pivot = left_counter;
end % function
function [element, stack] = pop(stack);

% Remove the top element from a stack, and return this element and the new
% stack. stack is a cell array of Matlab strings and element is a Matlab 
% string.
% YOUR NAME/NAMES, MONTH YEAR
element = stack(1,end);
stack = stack(1,1:end-1);
end
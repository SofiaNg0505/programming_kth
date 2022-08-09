clc
rpn('( 300 + 522 ) * 150');
function val = rpn(i_string)

% A calculator that takes an expression in infix format (as a Matlab 
% string), translates it to RPN format and evaluates it. i_string is a
% Matlab string.
% YOUR NAME/NAMES, MONTH YEAR

r_string = infix_to_rpn(i_string); %
% Note the difference between a Matlab string "xxx" and a character array
% 'xxx'. They both represent strings of characters but are different 
% formats. The fprintf() function below takes character array as input and 
% thus the Matlab string r_string has to be transformed using char().
fprintf(['In RPN notation: ', char(r_string), '\n']); 

val = eval_rpn(r_string);
% The num2str() function is used to transform val into a character array.
fprintf(['Result of evaluation: ', num2str(val), '\n']); 
end


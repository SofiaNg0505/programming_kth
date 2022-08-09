function val = eval_rpn(r_string)

% Evaluation of an expression in RPN format. r_string is a Matlab string
% and val a numeric.
% YOUR NAME/NAMES, MONTH YEAR

% Constants
operands = ["0" "1" "2" "3" "4" "5" "6" "7" "8" "9"];
operators = ["*" "/" "+" "-"];
stack = {};
% Internal variables
r_array = strsplit(r_string);   % array of symbols in RPN format
% ...
for i=1:length(r_array)
    if contains(r_array(i),operands)
        stack = push(r_array(i),stack);
    elseif contains(r_array(i),operators)
        %char([stack(end-1),r_array(i),stack(end)])
        poop=str2num(string(stack(end-1)));
        poop2=str2num(string(stack(end)));
        if contains(string(r_array(i)),'+')
            stack(end-1)={poop+poop2};
            stack(end) = [];
        elseif contains(string(r_array(i)),'-')
            stack(end-1)={poop-poop2};
            stack(end) = [];
        elseif contains(string(r_array(i)),'*')
            stack(end-1)={poop*poop2};
            stack(end) = [];
        elseif contains(string(r_array(i)),'/')
            stack(end-1)={poop/poop2};
            stack(end) = [];
        end
        %...
    end
    % ...
    % A tip is to use the function contains() to check symbols in r_array.

end
size(stack)
stack
val = str2num(string(stack)); % ...
end


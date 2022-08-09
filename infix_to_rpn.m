function r_string = infix_to_rpn(i_string)
% Translation of an expression from infix to RPN format. i_string and
% r_string are Matlab strings.
% YOUR NAME/NAMES, MONTH YEAR
i_array = strsplit(i_string);

% Constants
operands = ["0" "1" "2" "3" "4" "5" "6" "7" "8" "9"];
operators = ["*" "/" "+" "-"];

% Internal variables
% array of symbols in infix format
r_array = [];                   % array of symbols in rpn format
stack = {};
for i=1:length(i_array)
    if contains(i_array(i),operands)
        r_array=[r_array,i_array(i)];
    elseif contains(i_array(i),'(')
        stack=push(i_array(i),stack);
    elseif contains(i_array(i),')')
        while ~contains(string(stack(end)),'(')
            [element, stack] = pop(stack);
            r_array=[r_array,element];
        end
        [element, stack] = pop(stack);
    elseif contains(i_array(i),operators)
        while ~length(stack)==0 && ~contains(string(stack(end)),'(')
            if  not(p(string(stack(end)))<p(string(i_array(i))))
                [element,stack]=pop(stack);
                r_array=[r_array,element];
            else
                break
            end
        end
        stack=push(i_array(i),stack);
    elseif contains(i_array(i),' ')
    else
        error('Wrong input!')
    end %if

    % ...
    % A tip is to use the function contains() to check symbols in i_array.
end %for
r_array=[r_array,stack];
r_string = strjoin(r_array);
end


close all; clear; clc;
syms x b; % initializing symbolic variables

f = x^3 + 7*b*x - 8; % function to be solved
x_0 = 0;  % starting point

%soln = symb_newton_method_cubic_example(f, x_0, iter); % call newton function to solve f
b_set = 100 : 100: 1000; % starting point
iter = length(b_set); % number of iterations

soln_new = zeros(length(b_set),length(b_set));

for i  = 1: iter
    %subplot(2, iter/2, i)
    soln = symb_newton_method_cubic_example(f, x_0, iter); % call newton function to solve f  
    b = b_set(i);
    soln_new(i,:)= double(subs(soln)); % substitute x into soln to solve symbolic output
    %x_0 = soln_new; % update x
    %plot(soln_new);
    %title ([ 'b = ' num2str(b)])
end

for j = 1:iter
    figure(j)
    h(j) = animatedline; % initiate animation
    file_num = sprintf('Example_1_video_%d',j);
    vidObj = VideoWriter(file_num);
    vidObj.FrameRate = 1; % set the seconds per image
    open(vidObj);
    for i_new = 1:iter
        addpoints(h(j), b_set(i_new), soln_new(j,i_new));
        drawnow
        xlim([0 1050])
        if j == 1
            ylim([0 0.052111111])
        elseif j == 2
            ylim([0 0.0058111])
        elseif j == 3
            ylim([0 0.0039111])
        elseif j == 4 
            ylim([0 0.0029991])
        else
            ylim([0 0.00241111])
        end
        pause(1);
        title (['b has value ' num2str(b_set(j))])
        M = getframe(gcf);  % save animated plot
        writeVideo(vidObj, M); % write the video
        
    end
    %title (['b has value ' num2str(b_set(j))])
    saveas(figure(j), sprintf('figure_%d_Example_1.png',j));
    close(vidObj); % close the writer object
    
end

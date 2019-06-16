close all; clear; clc
syms x b; % initializing symbolic variables
%iter = 10; % number of iterations
f = x^b; % function to be solved
x_0 = 0.1; % starting point

b_set = 100 : 100: 1000; % starting point
iter = length(b_set); % number of iterations
soln_new = zeros(length(b_set),length(b_set));

for i  = 1: iter
    soln = symb_newton_method_cubic_example(f, x_0, iter); % call newton function to solve f  
    b = b_set(i);
    soln_new(i,:) = double(subs(soln)); % substitute x into soln to solve symbolic output

end

for j = 1:iter
    figure(j)
    h(j) = animatedline; % initiate animation
    file_num = sprintf('Example_3_video_%d',j);
    vidObj = VideoWriter(file_num);
    vidObj.FrameRate = 1; % set the seconds per image
    open(vidObj);
    for i_new = 1:iter
        addpoints(h(j), b_set(i_new), soln_new(j,i_new));
        drawnow
        xlim([0 1050])
        ylim([0 0.2])
        
        pause(1);
        
        title (['b has value ' num2str(b_set(j))])
        M = getframe(gcf);  % save animated plot
        writeVideo(vidObj, M); % write the video
           
    end
    
    %title (['b has value ' num2str(b_set(j))])
    saveas(figure(j), sprintf('figure_%d_Example_3.png',j));
    
    file_num = sprintf('Example_%d',j);

    close(vidObj); % close the writer object
    
end

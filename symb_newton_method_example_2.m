clear; close all; clc;
syms x b; % initializing symbolic variables
f = 1 - x^2; % function to be solved
x_0 = 0.00001 : 0.001: 0.01; % starting point
iter = length(x_0); % number of iterations
soln_new = zeros(length(x_0),length(x_0));

for i  = 1: iter
    x_1 = x_0(i); % starting point
    soln = symb_newton_method_cubic_example(f, x_1, iter); % call newton function to solve f  
    soln_new(i,:) = double(subs(soln)); % substitute x into soln to solve symbolic output

end

for j = 1:iter
    figure(j)
    h(j) = animatedline; % initiate animation
    file_num = sprintf('Example_2_video_%d',j);
    vidObj = VideoWriter(file_num);
    vidObj.FrameRate = 1; % set the seconds per image
    open(vidObj);
    for i_new = 1:length(x_0)
        addpoints(h(j), x_0(i_new), soln_new(j,i_new));
        drawnow
        xlim([0.00001 0.01])
        if j == 1
            ylim([0 60000])
        elseif j == 2
            ylim([0 510])
        elseif j == 3  
            ylim([0 260])
        elseif j == 4 || 5
            ylim([0 160])
        elseif j == 6 || 7
            ylim([0 110])
        elseif j == 8 || 9
            ylim([0 85])
        elseif j == 10
            ylim([0 70])
        end
        %size(M(i).cdata);
        pause(1);
        title (['x has value ' num2str(x_0(j))])
        M = getframe(gcf);  % save animated plot
        
        writeVideo(vidObj, M);
        
    end
    %title (['x has value ' num2str(x_0(j))])
    saveas(figure(j), sprintf('figure_%d_Example_2.png',j));
    
    close(vidObj); % close the writer object
    
end











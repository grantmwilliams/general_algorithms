%% Monkey Evolutionary Algorithm
clear;close all;clc;
tic
target = ('MORE GIDDY IN MY DESIRES THAN A MONKEY');
ideal = double(target);
best = inf;
Gen = 0;
phrase = randi([min(ideal) max(ideal)],1,length(target));
for Gen = 1:1e6 %arbitrarily large
    % Monkey 1
    Pop = repmat(phrase,50,1);
    idx = mod(bsxfun(@plus,randi([0 length(target)-1], 50, 1),repmat([0:length(target)-1], 50, 1)), length(target))==0;
    Pop(idx) = round(rand([1,sum(sum(idx))])*(max(ideal)-1)+1);
    [F1, idx2] = min(sum(abs(bsxfun(@minus,Pop,ideal)),2));
    M1 = Pop(idx2,:);
    
    % Monkey 2
    M2 = randi([min(ideal) max(ideal)],1,length(ideal));
    F2 = sum(abs(M2-ideal));
    
    if (F1 < best && F1 < F2)
        best = F1;
        phrase = M1;
        fprintf('Gen: %d  |  Fitness: %d  |  ',Gen, best);
        disp(char(phrase));
    elseif (F2 < best && F2 < F1)
        best = F2;
        phrase = M2;
        fprintf('Gen: %d  |  Fitness: %d  |  ',Gen, best);
        disp(char(phrase));
    end
    if (best == 0)
        break;
    end
    
end
disp('Final Solution');
disp('--------------------------------------------------');
disp(char(phrase));

toc

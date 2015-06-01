function xy = normalizeXY(xy,variableRange)
% Normalizes the range of xy to variableRange(1) <= xy <= variableRange(2)

%% Using For Loop
%% Initialize Vector
R1 = max(max(xy)) - min(min(xy));
for i = 1:length(xy);
    A = xy(i,:); % Grab One Row of xy
    
%% Normalize to 0 <= A <= 1
    
    A = (A-min(min(xy)))/R1;
%% Scale to X <= A <= Y
    R2 = variableRange(2)-variableRange(1);
    A = A*R2 + variableRange(1);
    
%% Replace Row of xy with Normalized Version
    xy(i,:) = A;
end

%% Vectorized Version (Currently Less Accurate)
% xy(:,1) = bsxfun(@plus,(bsxfun(@times,variableRange(2)-variableRange(1),(bsxfun(@times, bsxfun(@minus, xy(:,1), min(xy(:,1))), 1./abs(max(xy(:,1)) - min(xy(:,1))))))),variableRange(1));
% xy(:,2) = bsxfun(@plus,(bsxfun(@times,variableRange(2)-variableRange(1),(bsxfun(@times, bsxfun(@minus, xy(:,2), min(xy(:,2))), 1./abs(max(xy(:,2)) - min(xy(:,2))))))),variableRange(1));
end


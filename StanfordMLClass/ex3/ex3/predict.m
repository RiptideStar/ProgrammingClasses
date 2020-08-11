function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%

a1 = [ones(m,1) X]; %add a column of 1s at the first column of vector
z2 = a1 * Theta1'; %weight (theta1) and input (a1) from layer 1 becomes z for second layer
a2 = [ones(size(z2),1) sigmoid(z2)]; %add a column of ones to the start of z2, and then add the vector z that is contains its values sigmoided
z3 = a2*Theta2'; %weight (theta2) and input (a2) from layer 2 becomes z for third layer
a3 = sigmoid(z3); %final output is g(z) where g is sigmoid function

[pmax, imax] = max(a3, [], 2); %return max column and index of that column
p = imax; %that column with highest probability is the classifier returned

% =========================================================================


end

function [a0,a1]=linear_regression(x,y)
n = length(x);
a1 = (n*sum(x.*y) - sum(x)*sum(y))/(n*sum(x.^2) - (sum(x))^2);% the slope of the least squares regression line
a0 = mean(y)-a1*mean(x);
end
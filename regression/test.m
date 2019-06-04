x=[0 1 2 3 4 5 6 7 8]';% x is the iteration of the data
y=[-0.0075308	-0.0070737  -0.007072  -0.0070783 -0.007083 -0.0075308 -0.0070737 -0.007072 -0.0070783]';% y is the data value

[a0, a1]=linear_regression(x,y); % load linear_regression.m
x_model=0:0.001:10; 
y_model=a0+a1.*x_model;
plot(x,y,'x',x_model,y_model)
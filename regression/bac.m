x=data(:,1);% first import data as matrix into matlab,set x = data column 1, which is the iteration of the data
y=data(:,2);% set y = data column 2, which is the data value
p1=polyfit(x,y,1);f1=polyval(p1,x); % 1st order fit, y = polyval(p,x) returns the value of a polynomial of degree n evaluated at x
p2=polyfit(x,y,2);f2=polyval(p2,x);% 2nd order fit
p3=polyfit(x,y,3);f3=polyval(p3,x);% 3rd order fit
p4=polyfit(x,log(y),1);f4=polyval(p4,x);% log fit
res1=polyval(p1,x)-y; % residual of 1st order fit
res2=polyval(p2,x)-y;
res3=polyval(p3,x)-y;
res4=exp(polyval(p4,x))-y;

figure(1)
subplot(2,2,1),plot(x,y,'ko'), hold on, plot(x,f1,'k--'), grid on , title('1st Order Fit') 
% divides the current figure into an m-by-n grid and creates an axes for a subplot in the position specified by p, 
% hold on retains plots in the current axes so that new plots added to the axes do not delete existing plots
% grid on displays the major grid lines for the current axes

subplot(2,2,2),plot(x,y,'ko'), hold on, plot(x,f2,'k--'), grid on , title('2nd Order Fit')
subplot(2,2,3),plot(x,y,'ko'), hold on, plot(x,f3,'k--'), grid on , title('3rd Order Fit')
subplot(2,2,4),plot(x,log(y),'ko'), hold on, plot(x,f4,'k--'), grid on , title('Logarithmic Fit')
figure(2)
subplot(2,2,1),plot(x,res1,'k*'), grid on , title('1st Order Residuals')
subplot(2,2,2),plot(x,res2,'k*'), grid on , title('2nd Order Residuals')
subplot(2,2,3),plot(x,res3,'k*'), grid on , title('3rd Order Residuals')
subplot(2,2,4),plot(x,res4,'k*'), grid on , title('Logarithmic Residuals')

% type "bac" in Matlab command window to see the results
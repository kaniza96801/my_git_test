#include<iostream>
#include<Eigen/Dense>

using Eigen::MatrixXd;
using namespace Eigen;


int main()
{
char menu ='\n';
int row,col,temp;
while(1)
{
std::cout<<"=========================================\n";
std::cout<<"1. Find determinant A\n";
std::cout<<"2. Find inverse A\n";
std::cout<<"3. Find eigenvector and eigenvalues of A\n";
std::cout<<"4. Find least square solution of A\n";
std::cout<<"5. Column space basis and Rank of A\n";
std::cout<<"6. Exit the program\n";
std::cout<<"=========================================\n";
std::cout<<"Select your want: ";
std::cin>>menu;
  
switch(menu)
{
 case '1':
  std::cout<<"input the maximum row size: ";
  std::cin>>row;
  std::cout<<"input the maximum col size: ";
  std::cin>>col;
  std::cout<<row<<" X "<<col<<" matrix\n";
  MatrixXd A(row,col);
  temp = row*col;
  std::cout<<"input Matrix A: \n";
  for(int i=0; i<row;i++)
  {
      for(int j=0; j<col; j++)
      {
          std::cin>>A(i,j);
      }
  }
  std::cout<< "The determinant of A is "<<A.determinant();
  break;
case '2':
  std::cout<<"input the maximum row size: ";
  std::cin>>row;
  std::cout<<"input the maximum col size: ";
  std::cin>>col;
  std::cout<<row<<" X "<<col<<" matrix\n";
  MatrixXd A(row,col);
  temp = row*col;
  std::cout<<"input Matrix A: \n";
  for(int i=0; i<row;i++)
  {
      for(int j=0; j<col; j++)
      {
          std::cin>>A(i,j);
      }
  }
  if(row==col)
  {
      if(A.determinant()==0)
      {
          std::cout<<"InvA not exists"<<'\n';
      }
      else
      {
          std::cout<<"inverse A: \n"<<A.inverse();
      }
  }
  break;
case '3':
  std::cout<<"input the maximum row size: ";
  std::cin>>row;
  std::cout<<"input the maximum col size: ";
  std::cin>>col;
  std::cout<<row<<" X "<<col<<" matrix\n";
  MatrixXd A(row,col);
  temp = row*col;
  std::cout<<"input Matrix A: \n";
  for(int i=0; i<row;i++)
  {
      for(int j=0; j<col; j++)
      {
          std::cin>>A(i,j);
      }
  }
  SelfAdjointEigenSolver<Matrix2f>
  eigensolver(A);
  if(eigensolver.info() != Success)
  {
    std::cout<< "The eigenvalues of A is "<<eigensolver.eigenvalues();
    std::cout<< "\nThe eigenvector of A is "<<eigensolver.eigenvectors();
  }
  else
  {
    std::cout<<"does not exist";
  }
  break;
case '4':
  std::cout<<"input the maximum row size: ";
  std::cin>>row;
  std::cout<<"input the maximum col size: ";
  std::cin>>col;
  std::cout<<row<<" X "<<col<<" matrix\n";
  MatrixXd A(row,col);
  temp = row*col;
  std::cout<<"input Matrix A: \n";
  for(int i=0; i<row;i++)
  {
      for(int j=0; j<col; j++)
      {
          std::cin>>A(i,j);
      }
  }
  VectorXd b(row);
  std::cout<<"input Vector B: \n";
  for(int k=0;k<row;k++)
  {
    std::cin>>b(k);
  }
  std::cout<<"The lease-squares solution is: "<<A.bdcSvd(ComputeThinU | ComputeThinV).solve(b);
  break;
case '5':
  std::cout<<"input the maximum row size: ";
  std::cin>>row;
  std::cout<<"input the maximum col size: ";
  std::cin>>col;
  std::cout<<row<<" X "<<col<<" matrix\n";
  MatrixXd A(row,col);
  temp = row*col;
  std::cout<<"input Matrix A: \n";
  for(int i=0; i<row;i++)
  {
      for(int j=0; j<col; j++)
      {
          std::cin>>A(i,j);
      }
  }
  std::cout<<"input Vector B: \n";
  for(int k=0;k<row;k++)
  {
    std::cin>>b(k);
  }
  std::cout<<"\nsoultions: \n"<<A.inverse()*b<<'\n';
  break;
case 6:
    return 0; 

} 

 
VectorXd b(row);
std::cout<<"input Vector B: \n";
for(int k=0;k<row;k++)
{
    std::cin>>b(k);
}
std::cout<<'\n'<<A<<'\n';
std::cout<<'\n'<<b<<'\n';
if(row==col)
{
    if(A.determinant()==0)
    {
        std::cout<<"InvA not exists"<<'\n';
        std::cout<<"infinite soultions"<<'\n';
    }
    else
    {
        std::cout<<"inverse A: \n"<<A.inverse();
        std::cout<<"\nsoultions: \n"<<A.inverse()*b<<'\n';
    }
    
}
}
return 0;

}

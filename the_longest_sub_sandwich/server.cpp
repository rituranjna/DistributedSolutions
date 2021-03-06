#include<iostream>
#include<cstring>
#include<sys/socket.h>
#include<netdb.h>
#include"common.h"
using namespace std;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";

//recived data here 
#define maxn 500000

char input[maxn];


string solve()
{
  //inout is incoming 

  string in_st = input;

  vector<ll> in = decode_input(in_st);
 
  ll lf = -(1LL<<60);
 
  ll tp=0;
  for(int i=0;i<((int)in.size());i++)
     {
       tp+=in[i];
       lf=max(lf,tp);
     }

  ll rt =  -(1LL<<60);
      tp=0;

  for(int i = ((int)in.size())-1;i>=0;i--)
   {
      tp+=in[i];
      rt=max(rt, tp);
  }


  return to_string(lf) + " " + to_string(rt);
}

int main(int argc, char *argv[] )
{

  //argc should be 2 for correct execution
  if ( argc != 2 )
  {
      printf( "usage: %s port_number \n", argv[0] );
	    return 0;
  }

  printf("Port Number is %s \n",argv[1] );

  struct  addrinfo host_info;
  struct  addrinfo  *host_list;//host_pointer is to store info 

  //poplulate pointer
  memset( &host_info , 0 ,sizeof(host_info));

  host_info.ai_family = AF_UNSPEC;
  host_info.ai_socktype = SOCK_STREAM;
  host_info.ai_flags = AI_PASSIVE;

  //server k lia localohost hi lena hai 
  int status = getaddrinfo( "localhost", argv[1], &host_info ,&host_list);

  if( status!=0)
  {
    cout<<"Error while getting addinfo "<<gai_strerror(status)<<endl;
  }
  else
  {
      cout<<"Got addinfo successfully "<<endl;
  }

 cout<<"Now creating socket\n";

 int sockid = socket(host_list->ai_family , host_list->ai_socktype,
		      host_list->ai_protocol);
  
                      
   print(host_list->ai_family);
   print(host_list->ai_socktype);
   print(host_list->ai_protocol);

 if( sockid == -1 )
   cout<<"ERROR while creating socket \n";
 else
   print(sockid);


  int yes = 1;
  // reuse if previous version was running due to xyz
  status = setsockopt( sockid , SOL_SOCKET , SO_REUSEADDR , &yes , sizeof(int) );

  //bind here 
  status = bind( sockid , host_list->ai_addr , host_list->ai_addrlen );

  if( status == -1 )
   cout<<" some error while BINDING"<<gai_strerror(status)<<endl;
  else
   cout<<"connected BINDING \n";

  //without bind() , oS will choose any port 
   //similarly ,on client side , we can use bind() to use a specific port


  //listen
  cout<<" now lostening .....";
   int backlog = 10;//number of request put in queue
   status = listen( sockid , backlog);

   if( status == -1 )
   cout<<" some error while Listening"<<gai_strerror(status)<<endl;
  else
   cout<<" listening ...\n";

  struct sockaddr_storage their_addr;
  socklen_t addr_size = sizeof(their_addr);

  //since on clinet side ,we are always creating a socket  ( BAD design lekin chalega )
  //to send , always ecpect server to create a new socket to recive and process data

  while(1)
  {
      int new_sock = accept(sockid, (struct sockaddr *)&their_addr, &addr_size);

      if( new_sock == -1)
       cout<<" some error while  creating a "<<gai_strerror(status)<<endl;
      else
       cout<<" ********* Acceted new request  *********** \n\n";
         

     
     int rec = recv ( new_sock , input , maxn , 0);

     print(rec);
     print(input);
     print( strlen(input) );

     cout<<" no processing the input\n";     

     string ans = solve();

     int sent = send( new_sock ,ans.c_str(), ans.size(), 0 );

     print(sent);

     close( new_sock);
     
      cout<<" ********* served new request  *********** \n\n";
  }

         
  return 0;
}

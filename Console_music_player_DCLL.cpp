#include<iostream>
#include<string>
using namespace std;
struct node
{
    struct node*next;
    string song;
    string singer;
    struct node*prev;
};
typedef struct node NODE;
typedef struct node*PNODE;
typedef struct node**PPNODE;

void Playlist(PNODE head)
{
PNODE abc=head;
if(head==NULL)
{
    cout<<"There is no song in your playlist...."<<endl;
}
else{
  cout<<"***...Song in playlist...***"<<endl;
  do{cout<<"***********************************"<<endl;
    cout<<"SONG...:"<<abc->song<<endl;
    cout<<"SINGER.:"<<abc->singer<<endl;
    cout<<"************************************"<<endl;
    abc=abc->next;
  }while(abc->next!=head);
   cout<<"*************************************"<<endl;
    cout<<"SONG...:"<<abc->song<<endl;
    cout<<"SINGER.:"<<abc->singer<<endl;
    cout<<"************************************"<<endl;
  }
}
void Insertfirst(PNODE& head)
{   string song;
    string singer;
    cout<<"Enter the name og song::(press $ to end)"<<endl;
    getline(cin,song,'$');
    cout<<"Enter the name of singer::(press $ to end)"<<endl;
    getline(cin,singer,'$');
    PNODE newnode=new node();
    newnode->singer=singer;
    newnode->song=song;
    if(head==NULL)
    {
      head=newnode;
      head->next=head;
      head->prev=head;
    }else{
       newnode->next=head;
       newnode->prev=head->prev;
       head->prev=newnode;
       head->prev->next=newnode;
       head=newnode;
    }
}
void Insertlast(PNODE& head)
{   string song;
    string singer;
    cout<<"Enter the name og song::(press $ to end)"<<endl;
    getline(cin,song,'$');
    cout<<"Enter the name of singer::(press $ to end)"<<endl;
    getline(cin,singer,'$');
    PNODE newnode=new node();
    newnode->singer=singer;
    newnode->song=song;
    if(head==NULL)
    {
      head=newnode;
      head->next=head;
      head->prev=head;
    }else{
        PNODE ptr=head;
        do{
           ptr=ptr->next;
        } while(ptr->next!=head);
        newnode->next=head;
        head->prev=newnode;
        head->prev->next=newnode;
        newnode->prev=head->prev;
    }
}
void Insertmid(PNODE& head)
{
    string song;
    string singer;
    cout<<"Enter the name og song::(press $ to end)"<<endl;
    getline(cin,song,'$');
    cout<<"Enter the name of singer::(press $ to end)"<<endl;
    getline(cin,singer,'$');
    PNODE newnode=new node();
    newnode->singer=singer;
    newnode->song=song;
    if(head==NULL)
    {
      head=newnode;
      head->next=head;
      head->prev=head;
    }else{
        PNODE ptr=head;
        int i=1;int index;
        cout<<"Index Position::::";
        cin >>index;
        while(i!=index-1)
        {
            ptr=ptr->next;
            i++;
        }; newnode->next=ptr;
        ptr->prev=newnode;
        ptr->prev->next=newnode;
        newnode->prev=ptr->prev;
    }
}
void Delete(PNODE head)
{
    PNODE ptr=head;
    int i=1;
    int index=0;
    if(head==NULL){
        cout<<"List is empty.....";
    }
    else{
    cout<<"Enter the index position:";
    cin>>index;
    while(i!=index){
        ptr=ptr->next;
         i++;
    }
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    free(ptr);
    cout<<"song delete succ..........";

    }
}
void Play(PNODE head)
{
    int i=1,index=0,ch=0;
    PNODE ptr=head;
    cout<<"**********************************************************"<<endl;
    cout<<"----------------------MUSIC PLAYING-----------------------"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<"Enter the song no to delete:"<<endl;
    cin>>index;
    while(i!=index){
        ptr=ptr->next;
        i++;
    }
      cout<<"Playing..............."<<endl;
      cout<<ptr->song<<endl;    
    do{
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"1.Previous"<<endl;
        cout<<"2.Next"<<endl;
        cout<<"3.|||PAUSE|||"<<endl;
        cout<<"4.Exit the player"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:
            ptr=ptr->prev;
            cout<<"Playing..............."<<endl;
            cout<<ptr->song<<endl; 
            break;
        case 2:
            ptr=ptr->next;
            cout<<"Playing..............."<<endl;
            cout<<ptr->song<<endl; 
        case 3:
              cout<<"Pause..............."<<endl;
              cout<<ptr->song<<endl;
        case 4:
              break; 
        default:
            break;
        } 
    }while(ch!=4); 
}
int main(int argc, char const *argv[])
{
    int ch=0;
   PNODE first=NULL;
   while(ch<7){
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"🎧🎸🎹🎺🎷.....MUSIC_LOVERS.....🎷🎺🎹🎸🎧"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"1.Display the Playlist..."<<endl;
    cout<<"2.Add new song to playlist...(Firstplace)"<<endl;
    cout<<"3.Add new song to playlist...(Lastplace)"<<endl;
    cout<<"4.Add new song to playlist...(Perticular position)"<<endl;
    cout<<"5.Remove song from playlist..."<<endl;
    cout<<"6.Play the song.......🎸🎸🎸"<<endl;
    cout<<"7.Quit the music...,"<<endl;
    cout<<"--------------------------------------------------------"<<endl<<endl<<endl;
    cout<<"Enter your choice:..:";
    cin>>ch;

    switch (ch)
    {
    case 1:
        Playlist(first);
        break;
    case 2:
         Insertfirst(first);
         break;
    case 3:
         Insertlast(first);
         break;
    case 4:
         Insertmid(first);
         break;
    case 5:
          Delete(first);
          break;
    case 6:
         Play(first);
         break;
    case 7:
         break;
    default:
        break;
    }
   }

    return 0;
}


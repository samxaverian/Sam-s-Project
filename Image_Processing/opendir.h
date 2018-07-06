#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

class OpenDir
{
public:
DIR *dir;
vector<string> images;
struct dirent *ent;
char path[1000];
void store_images()
{
//cout<<"enter the directory path:";
//cin>>path;
if ((dir = opendir (path)) != NULL)
{
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
      if(ent->d_name[0]!='.'){
          string s=(string)path + "/" + (string)ent->d_name;
          images.push_back(s);
    //printf ("%s\n", ent->d_name);
      }
  }
  closedir (dir);
} 
else
{
  /* could not open directory */
  perror ("");
}
/*vector<string>::iterator it=images.begin();
while(it!=images.end())
{
 cout<<it[0]<<endl;
 ++it;

}
*/
}
};
 

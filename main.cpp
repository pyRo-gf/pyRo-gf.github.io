#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main() {
		
int c,c1,c2,nri;

string fpar, string, title, author, image,thumbnail,video,embed,embedf,name,fname,profile, picture,ri,nm,email,paragraph="",ftitle="a_", article="",t,ablock,staffblk,field;

ifstream fread;
ifstream frart;


ofstream fwrite;


cout << "-------------------------------------------------------------------\n";
cout << "Theoretical and Computational Geophysics Website C++ Article Writer\n";
cout << "-------------------------------------------------------------------\n";
cout << "A simple C++ program to write HTML for TCG website\n";
cout << "\n";
cout << "[1] Write Article\n";
cout << "[2] Create new profile\n";
cout << "Choose Operation :";cin >> c;

if(c==1){
	cout << "\n------Write Article-------\n";
	cout << "Title :"; 
	cin.ignore(100,'\n');
	getline(cin,title);
	
	cout << "Author :";
	getline(cin,author);
	
	cout << "Thumbnail Pic (Foto harus berada pada directori /img)\n";
	cout << "Dimensi gambar harus 700x400 pixel\n";
	cout << "contoh:gambar.jpg\n";
	getline(cin,thumbnail);
	
	
	
	t=title;
	t.erase(remove_if(t.begin(), t.end(), ::isspace), t.end());	
	transform(t.begin(), t.end(), t.begin(), ::tolower); 
	if (t.length()>10)
		t.erase(t.begin()+10,t.end());
	
	ftitle += t;
	ftitle += ".html";
	
	fwrite.open(ftitle.c_str());
	frart.open("header");
	

	for(int i=0;frart.eof()!=true;i++)
		article += frart.get();
	article.erase(article.end()-1);
	
	frart.close();
	
	article+=title+"</h2>\n";
	article+="\t\t\t\t\t<p><i>"+author+"</i></p>\n";	
	
	int i=1;
	do{
	
		cout << "\n[1] Add Paragraph\n";
		cout << "[2] Add Image\n";
		cout << "[3] Add  Video\n";
		cout << "[4] Embed Youtube URL\n";
		cout << "[5] Finish Article\n";
		cout << "Choose operation :";
		cin >> c1;
	

		if(c1==1){
			cout << "Paragraf tidak perlu menggunakan attribut HTML hanya paragrah biasa." <<endl;
			cout << "Paragraf disave dalam bentuk text file."<<endl;
			cout << "File Paragraf harus didalam folder yang sama dengan program."<<endl;
			cout << "Paragraph file input (ex. paragraf1.txt) :"; cin >> fpar;
			
			article += "\t\t\t\t\t<p>";
			
			ifstream par;
			par.open(fpar.c_str());
			for(int i=0;par.eof()!=true;i++)
				article += par.get();
			article.erase(article.end()-1);
			par.close();
			
		
			
			article += "</p>\n";
			cout << "Succesfully added paragraph\n\n";
		}
		
		else if(c1==2){
			cout << "Masukkan nama gambar yang ingin dimasukan kedalam artikel.\n";
			cout << "File gambar harus ada didalam directory /img pada server tcg.\n";
			cout << "Extensi dapat berupa .jpg .png .gif dll.\n";
			cout << "File Gambar (ex. research1.jpg) : " ;
			cin >> image;
			article += "\t\t\t\t\t<div class=\"s-detailsImg\">\n\t\t\t\t\t\t<img src=\"img/"+image+"\" alt=\"\" class=\"img-fluid\">\n\t\t\t\t\t</div>\n";
			cout << "Succesfully added image\n\n";	
		}
		
		else if(c1==3){
			cout << "Masukkan nama video yang ingin dimasukan kedalam artikel.\n";
			cout << "File gambar harus ada didalam directory /vid pada server tcg.\n";
			cout << "Extensi harus berupa .mp4\n";
			cout << "File Video (ex. video1.mp4) : " ;
			cin >> video;
			article += "\t\t\t\t\t<div class=\"s-detailsImg\">\n\t\t\t\t\t\t<div class=\"embed-responsive embed-responsive-16by9\">\n\t\t\t\t\t<video width=\"320\" height=\"240\" controls>\n";
			article += "\t\t\t\t\t\t\t<source src=\"vid/"+video+"\" type=\"video/mp4\">\n\t\t\t\t\t\t\tYour browser does not support the video tag.\n\t\t\t\t\t\t</video>\n";
			article += "\t\t\t\t\t\t</div>\n\t\t\t\t\t</div>\n";
			cout << "Succesfully added video\n\n";
		}
		else if(c1==4){
			cout << "Masukkan kode embed video youtube \n";
			cout << "Contoh kode embed = \" <iframe width=\"969\" height=\"547\" src=\"https://www.youtube.com/embed/LqvLGx8I9QA\" frameborder=\"0\" allow=\"accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>\"";
			cout << "\nKode embed disimpan dalam bentuk .txt dalam folder yang sama dengan program\n";
			cout << "Kode embed (ex. embed1.txt):";
			cin >> embedf;
			

			ifstream ebd;
			ebd.open(embedf.c_str());
			
			for(int i=0;ebd.eof()!=true;i++)
				 embed += ebd.get();
			embed.erase(embed.end()-1);
			ebd.close();
			
			
			article += "\t\t\t\t\t<div class=\"s-detailsImg\">\n\t\t\t\t\t\t<div class=\"embed-responsive embed-responsive-16by9\">\n";
			article += embed + "\n\t\t\t\t\t\t</div>\n\t\t\t\t\t</div>\n";
			cout << "Succesfully added embed code\n\n";
		}
		else if(c1==5){
			cout << "Succesfully Created HTML Article";
		}
		else cout << "Wrong input";

	} while(c1!=5);
	
	ifstream footer;
	footer.open("footer");
	for(int i=0;footer.eof()!=true;i++)
		article += footer.get();
	article.erase(article.end()-1);
	footer.close();
	
	fwrite << article;
	fwrite.close();	
	
	
	ifstream rblock;
	rblock.open("ablock1");
	for(int i=0;rblock.eof()!=true;i++)
		ablock += rblock.get();
	ablock.erase(ablock.end()-1);
	rblock.close();
	
	
	ablock +="\n\t\t\t\t\t<a href=\""+ftitle+"><div class=\"single-profile-front\">\n";
	ablock +="\t\t\t\t\t\t<div class=\"profile-img\">\n";
	ablock +="\t\t\t\t\t\t\t<img src=\""+thumbnail+"\" alt=\"\">\n";
	ablock +="\t\t\t\t\t\t</div>\n";
	ablock +="\t\t\t\t\t\t<div class=\"profile-caption\">\n";
	ablock +="\t\t\t\t\t\t\t<h4><a href=\""+ftitle+"\">"+title+"</a></h4>\n";
	ablock +="\t\t\t\t\t\t\t<p>"+author+"</p>\n";
	ablock +="\t\t\t\t\t\t</div>\n";
	ablock +="\t\t\t\t\t</div></a>\n";
	ablock +="\t\t\t\t</div>\n";
	ablock +="\t\t\t</div>\n";
	

	
	ofstream wblock;
	wblock.open("Article Block.txt");
	wblock << ablock;
	wblock.close();
}

else if(c==2){
	cout << "\n------Create Profile-------\n";
	cout << "Name :"; 
	cin.ignore(100,'\n');
	getline(cin,name);
	
	cout << "Profile Picture (Foto harus berada pada directory /img. contoh:jaka.jpg):\n";
	cout << "Dimensi foto harus 362x241 pixel\n";
	cout << "Nama File Foto : ";
	getline(cin,picture);
	
	cout << "Position or Field(Student/Fluid Dynamic/Numerical Method):";
	getline(cin,field);
	
	nm=name;
	nm.erase(remove_if(nm.begin(), nm.end(), ::isspace), nm.end());
	transform(nm.begin(), nm.end(), nm.begin(), ::tolower); 
	if (nm.length()>10)
		nm.erase (nm.begin()+10,nm.end());
	
	ofstream fwprof;
	ifstream hprof;
	
	fname += "p_"+nm;
	fname += ".html";
	fwprof.open(fname.c_str());
	hprof.open("profheader");
	
	for(int i=0;hprof.eof()!=true;i++)
		profile += hprof.get();
	profile.erase(profile.end()-1);
	
	hprof.close();
	
	profile+="\n\t\t\t\t\t\t\t<img src=\"img/"+picture+"\">\n";
	
	hprof.open("pheader2");
	
	for(int i=0;hprof.eof()!=true;i++)
		profile += hprof.get();
	profile.erase(profile.end()-1);
	
	hprof.close();
	
	profile+="\n\t\t\t\t\t\t\t\t<h3><b>"+name+"</b3></h3>\n\t\t\t\t\t\t\t</div>\n";
	
	cout << "Reasearch Interest\n";
	cout << "How many research interest?1-100 :";
	cin >> nri;
	
	profile+="\t\t\t\t\t\t\t<h3>Research Interest</h3>\n";
	profile+="\t\t\t\t\t\t\t<div class=\"\">\n";
	profile+="\t\t\t\t\t\t\t<ol>\n";
	
	
	for(int i=0;i<nri;i++){
		cout << "Research interest-"<<i+1<<" : ";
		cin.ignore(1,'\n');
		getline(cin,ri);
		profile += "\t\t\t\t\t\t\t\t<li><span>" +ri+"</span></li>";
		profile += "\n";
		
	}
	
	profile+="\n\t\t\t\t\t\t\t</ol>\n";
	profile+="\t\t\t\t\t\t\t</div>\n";
	profile+="\t\t\t\t\t\t\t<h3>Research Group</h3>\n";
	profile+="\t\t\t\t\t\t\t<p>Lab. Teori dan Komputasi Geofisika <br>Fakultas Matematika dan Ilmu Pengetahuan Alam <br>Universitas Padjadjaran</p>\n";
	
	cout << "Email : ";
	cin >> email;
	
	profile+="\t\t\t\t\t\t\t<h3>Email</h3>\n";
	profile+="\t\t\t\t\t\t\t<p>"+email+"</p>\n";
	
	hprof.open("pfooter");
	
	for(int i=0;hprof.eof()!=true;i++)
		profile += hprof.get();
	profile.erase(profile.end()-1);
	
	hprof.close();	
	
	fwprof << profile;
	fwprof.close();	
	
	
	ifstream rstaf;
	rstaf.open("profileblock");
	for(int i=0;rstaf.eof()!=true;i++)
		staffblk += rstaf.get();
	staffblk.erase(staffblk.end()-1);
	rstaf.close();
	
	staffblk +="\n\t\t\t\t\t\t<a href=\""+fname+"><div class=\"recent-img\">\n";
	staffblk +="\t\t\t\t\t\t\t<img src=\""+picture +"\">\n";
	staffblk +="\t\t\t\t\t\t</div></a>\n";
	staffblk +="\t\t\t\t\t\t<div class=\"recent-cap\">\n";
	staffblk +="\t\t\t\t\t\t\t<h4><a href=\""+ fname+"\">"+name+"</a></h4>\n";
	staffblk +="\t\t\t\t\t\t\t<p>"+ field+"</p>\n";
	staffblk +="\t\t\t\t\t\t</div>\n";
	staffblk +="\t\t\t\t\t</div>\n";
	staffblk +="\t\t\t\t\</div>\n";
	staffblk +="\t\t\t\t\<!-------------- Staff Block End----------------------->\n";

	ofstream wstaff;
	wstaff.open("Staff Block.txt");
	wstaff << staffblk;
	wstaff.close();
	
}

else cout << "Invalid input";



return 0;

}

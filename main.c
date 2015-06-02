#include <allegro.h>
#include <stdlib.h>
#include <time.h>

float x=250;
int y =350;
float o=-1000,a=-1000;
float vn = 0.10;
volatile int b;
int score =0;
int life = 100;
int DEAD = 0;
int perg = 0;
void tempo(){
   b++;     
}
END_OF_FUNCTION(tempo);

struct niveis{
    BITMAP *nivel;       
}  nivel[6];

struct meteoro{
    BITMAP *mete; 
    int desenha;      
}  mete[6];

struct missao{
     BITMAP *missao;       
}missaos[3];

struct perguntas{
    BITMAP *perg;
    BITMAP *o1;
    BITMAP *o2;
    BITMAP *o3;
    BITMAP *o4;
       
} perguntas[13];

float geraY(float y){
     return y+vn;
}

int main(){
    allegro_init();
    install_timer();
    install_keyboard();
    install_mouse();
    
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT,640,480,0,0);
    
    b = 0;    
    LOCK_FUNCTION(tempo);
    LOCK_VARIABLE(b);
    install_int_ex(tempo,1000000);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
    
    PALETTE pal; 
    BITMAP *buffer = create_bitmap(640,480);
    BITMAP *img = create_bitmap(0,20);
    BITMAP *nave = load_bitmap("sprites/nave.bmp",pal);
    BITMAP *fundo = load_bitmap("sprites/espaco2.bmp",pal);
    BITMAP *cursor = load_bitmap("sprites/mouse.bmp",pal);
    BITMAP *dead = load_bitmap("sprites/dead2.bmp",pal);
    BITMAP *win = load_bitmap("sprites/win2.bmp",pal);
    
    missaos[0].missao = load_bitmap("sprites/n1m.bmp",pal);
    missaos[1].missao = load_bitmap("sprites/n2m.bmp",pal);
    missaos[2].missao = load_bitmap("sprites/n3m.bmp",pal);
        
    perguntas[0].perg= load_bitmap("sprites/N1P1_1.bmp",pal);
    perguntas[1].perg= load_bitmap("sprites/N1P1_2.bmp",pal);
    perguntas[2].perg= load_bitmap("sprites/N1P2.bmp",pal);
    perguntas[3].perg= load_bitmap("sprites/N1P3.bmp",pal);
    perguntas[4].perg= load_bitmap("sprites/N1P4.bmp",pal);
    perguntas[5].perg= load_bitmap("sprites/N2P1.bmp",pal);
    perguntas[6].perg= load_bitmap("sprites/N2P2.bmp",pal);
    perguntas[7].perg= load_bitmap("sprites/N2P3.bmp",pal);
    perguntas[8].perg= load_bitmap("sprites/N2P4.bmp",pal);
    perguntas[9].perg= load_bitmap("sprites/N3P1.bmp",pal);
    perguntas[10].perg= load_bitmap("sprites/N3P2.bmp",pal);
    perguntas[11].perg= load_bitmap("sprites/N3P3.bmp",pal);
    perguntas[11].perg= load_bitmap("sprites/N3P4.bmp",pal);
    
    perguntas[0].o1 = load_bitmap("sprites/n1p1a.bmp",pal);
    perguntas[0].o2 = load_bitmap("sprites/n1p1b.bmp",pal);
    perguntas[0].o3 = load_bitmap("sprites/n1p1c.bmp",pal);
    perguntas[0].o4 = load_bitmap("sprites/n1p1d.bmp",pal);

    perguntas[1].o1 = load_bitmap("sprites/missao.bmp",pal);
    perguntas[1].o2 = load_bitmap("sprites/missao.bmp",pal);
    perguntas[1].o3 = load_bitmap("sprites/missao.bmp",pal);
    perguntas[1].o4 = load_bitmap("sprites/missao.bmp",pal);
    
    perguntas[2].o1 = load_bitmap("sprites/n1p2a.bmp",pal);
    perguntas[2].o2 = load_bitmap("sprites/n1p2b.bmp",pal);
    perguntas[2].o3 = load_bitmap("sprites/n1p2c.bmp",pal);
    perguntas[2].o4 = load_bitmap("sprites/n1p2d.bmp",pal);
    
    perguntas[3].o1 = load_bitmap("sprites/n1p3a.bmp",pal);
    perguntas[3].o2 = load_bitmap("sprites/n1p3b.bmp",pal);
    perguntas[3].o3 = load_bitmap("sprites/n1p3c.bmp",pal);
    perguntas[3].o4 = load_bitmap("sprites/n1p3d.bmp",pal);
    
    
    perguntas[4].o1 = load_bitmap("sprites/n1p4a.bmp",pal);
    perguntas[4].o2 = load_bitmap("sprites/n1p4b.bmp",pal);
    perguntas[4].o3 = load_bitmap("sprites/n1p4c.bmp",pal);
    perguntas[4].o4 = load_bitmap("sprites/n1p4d.bmp",pal);
    
    perguntas[5].o1 = load_bitmap("sprites/n2p1a.bmp",pal);
    perguntas[5].o2 = load_bitmap("sprites/n2p1b.bmp",pal);
    perguntas[5].o3 = load_bitmap("sprites/n2p1c.bmp",pal);
    perguntas[5].o4 = load_bitmap("sprites/n2p1d.bmp",pal);
    
    perguntas[6].o1 = load_bitmap("sprites/n2p2a.bmp",pal);
    perguntas[6].o2 = load_bitmap("sprites/n2p2b.bmp",pal);
    perguntas[6].o3 = load_bitmap("sprites/n2p2c.bmp",pal);
    perguntas[6].o4 = load_bitmap("sprites/n2p2d.bmp",pal);
    
    perguntas[7].o1 = load_bitmap("sprites/n2p3a.bmp",pal);
    perguntas[7].o2 = load_bitmap("sprites/n2p3b.bmp",pal);
    perguntas[7].o3 = load_bitmap("sprites/n2p3c.bmp",pal);
    perguntas[7].o4 = load_bitmap("sprites/n2p3d.bmp",pal);
    
    perguntas[8].o1 = load_bitmap("sprites/n2p4a.bmp",pal);
    perguntas[8].o2 = load_bitmap("sprites/n2p4b.bmp",pal);
    perguntas[8].o3 = load_bitmap("sprites/n2p4c.bmp",pal);
    perguntas[8].o4 = load_bitmap("sprites/n2p4d.bmp",pal);
    
    perguntas[9].o1 = load_bitmap("sprites/n3p1a.bmp",pal);
    perguntas[9].o2 = load_bitmap("sprites/n3p1b.bmp",pal);
    perguntas[9].o3 = load_bitmap("sprites/n3p1c.bmp",pal);
    perguntas[9].o4 = load_bitmap("sprites/n3p1d.bmp",pal);
    
    perguntas[10].o1 = load_bitmap("sprites/n3p2a.bmp",pal);
    perguntas[10].o2 = load_bitmap("sprites/n3p2b.bmp",pal);
    perguntas[10].o3 = load_bitmap("sprites/n3p2c.bmp",pal);
    perguntas[10].o4 = load_bitmap("sprites/n3p2d.bmp",pal);
    
    perguntas[11].o1 = load_bitmap("sprites/n3p3a.bmp",pal);
    perguntas[11].o2 = load_bitmap("sprites/n3p3b.bmp",pal);
    perguntas[11].o3 = load_bitmap("sprites/n3p3c.bmp",pal);
    perguntas[11].o4 = load_bitmap("sprites/n3p3d.bmp",pal);
    
    perguntas[12].o1 = load_bitmap("sprites/n3p4a.bmp",pal);
    perguntas[12].o2 = load_bitmap("sprites/n3p4b.bmp",pal);
    perguntas[12].o3 = load_bitmap("sprites/n3p4c.bmp",pal);
    perguntas[12].o4 = load_bitmap("sprites/n3p4d.bmp",pal);
    

      
    
    MIDI *somfundo = load_midi("sounds/starwaytoheaven.mid");
    
    nivel[0].nivel = load_bitmap("sprites/nivel1.bmp",pal);
    nivel[1].nivel = load_bitmap("sprites/nivel2.bmp",pal);
    nivel[2].nivel = load_bitmap("sprites/nivel3.bmp",pal);
    nivel[3].nivel = load_bitmap("sprites/nivel1c.bmp",pal);
    nivel[4].nivel = load_bitmap("sprites/nivel2c.bmp",pal);
    nivel[5].nivel = load_bitmap("sprites/nivel3c.bmp",pal);
    
    mete[0].mete = load_bitmap("sprites/mete1.bmp",pal);
    mete[1].mete = load_bitmap("sprites/mete2.bmp",pal);
    mete[2].mete = load_bitmap("sprites/mete3.bmp",pal);
    mete[3].mete = load_bitmap("sprites/mete4.bmp",pal);
    mete[4].mete = load_bitmap("sprites/mete5.bmp",pal);
    mete[5].mete = load_bitmap("sprites/mete6.bmp",pal);
    
    mete[0].desenha = 0;
    mete[1].desenha = 0;
    mete[2].desenha = 0;
    mete[3].desenha = 0;
    mete[4].desenha = 0;
    mete[5].desenha = 0;
    
    int controla = 0;
    int cmissao = 0, cresto=0, qmissao=0;
    float ym=0,ym2=-100;
    int xm,xm2; 
    int bateu =0;
    int a, nl=1,qpergunta=1;
    
   // play_midi(somfundo,1);   
    int w,ind=0;
    srand( (unsigned)time(NULL) );
    xm = rand()%600;
    xm2 = rand()%600;
    while(!key[KEY_ESC]){ 
        clear(buffer);                    
       if(controla==1){
            if(cmissao==0){           
                draw_sprite(buffer,missaos[qmissao].missao,50,450-(b+40));                       
                  if(mouse_b==1 && b>1){
                      cmissao = 1; 
                      cresto = 1; 
                      perg =0;      
                   }                  
                 draw_sprite(buffer,cursor,mouse_x-45,mouse_y-17);
             }
             /*Parte Principal*/
            if(cresto==1){
               if(life>0){             
                   if(score<1000){   
                       
                      if (score ==50)
                         perg =1;
                      if(score==160)
                         perg =1;
                      if(score==270)
                         perg =1;
                      if(score==380)
                         perg=1; 
                       if(perg ==0){                           
                           if(key[KEY_RIGHT]){
                              if(x<540)
                                 x+=0.25;                              
                           }
                           if(key[KEY_LEFT]){
                              if(x>0)
                                x-=0.25;                                       
                            }
                           if(ym>475){
                              ym =0;
                              
                              for(a=0;a<5;a++){
                                if(mete[a].desenha==1){
                                   bateu =1;                       
                                }
                                mete[a].desenha =0;                
                              }
                              if(bateu==0)
                                score+=50;
                              bateu =0;
                              xm= rand()%600;          
                           }
                           ym = geraY(ym); 
                        
                           draw_sprite(buffer,fundo,0,0); 
                           
                           rectfill( buffer, 5, 10, 3*life, 20, makecol( 200, 200, 40 ) ); 
                           textprintf_ex(buffer, font, 150, 13, makecol(255,40,40),-1, "Life: %d%%", life);
                           textprintf_ex(buffer, font, 500, 10, makecol(255,255,0),-1, "Score: %d", score);
                           
                           for(w=0;w<=400;w+=100){
                               if(ym>310 && (xm+w)<(x+100) && (xm+w)>(x-75)&& mete[ind].desenha ==0){
                                          mete[ind].desenha =1;
                                          life-=10;
                               }
                               else{
                                   if(mete[ind].desenha ==0) 
                                        draw_sprite(buffer,mete[ind].mete,xm+w,ym);
                                   else
                                       draw_sprite(buffer,mete[ind].mete,xm+6000,-10000);    
                               }
                               ind++;    
                           }
                           ind =0;
                           draw_sprite(buffer,nave,x,350);
                        }else{
                            if(nl==1){
                                  if(qpergunta==1){
                                       draw_sprite(buffer,perguntas[0].perg,10,10); 
                                       draw_sprite(buffer,perguntas[1].perg,10,50);
                                       draw_sprite(buffer,perguntas[0].o1,10,100); 
                                       draw_sprite(buffer,perguntas[0].o2,10,200); 
                                       draw_sprite(buffer,perguntas[0].o3,10,300); 
                                       draw_sprite(buffer,perguntas[0].o4,10,400);
                                       if(mouse_x-45>=-35 && mouse_x-45 <=105 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead =0;
                                                  controla =1;
                                               }            
                                        }
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                              dead=0;
                                              controla =1;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                             dead=0;
                                             controla =1;
                                           }            
                                        }
                                        if(mouse_x-45>=-35&& mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                             dead=0;
                                             controla =1;
                                           }            
                                        }            
                                  }
                                  else if(qpergunta==2){
                                       textprintf_ex(buffer, font, 150, 13, makecol(255,40,40),-1, "qpergunta: %d", qpergunta);
                                       draw_sprite(buffer,perguntas[2].perg,10,10); 
                                       draw_sprite(buffer,perguntas[2].o1,10,100); 
                                       draw_sprite(buffer,perguntas[2].o2,10,200); 
                                       draw_sprite(buffer,perguntas[2].o3,10,300); 
                                       draw_sprite(buffer,perguntas[2].o4,10,400); 
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){           
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead=0;
                                                  controla =1;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                              dead=0;
                                              controla =1;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                             dead=0;
                                             controla =1;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                             dead=0;
                                             controla =1;
                                           }            
                                        }
                                  }
                                  else if(qpergunta==3){
                                       draw_sprite(buffer,perguntas[3].perg,10,10); 
                                       draw_sprite(buffer,perguntas[3].o1,10,100); 
                                       draw_sprite(buffer,perguntas[3].o2,10,200); 
                                       draw_sprite(buffer,perguntas[3].o3,10,300); 
                                       draw_sprite(buffer,perguntas[3].o4,10,400);
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                  }
                                  else if(qpergunta==4){
                                       draw_sprite(buffer,perguntas[4].perg,10,10); 
                                       draw_sprite(buffer,perguntas[4].o1,10,100); 
                                       draw_sprite(buffer,perguntas[4].o2,10,200); 
                                       draw_sprite(buffer,perguntas[4].o3,10,300); 
                                       draw_sprite(buffer,perguntas[4].o4,10,400);
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185&& mouse_y-17 <=200){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }     
                                  }
                                  else{    
                                    perg =0;
                                    dead=0;
                                    controla=1;
                                    score++;  
                                  }
                            }
                            else if(nl==2){
                                 if(qpergunta==1){
                                       draw_sprite(buffer,perguntas[5].perg,10,10); 
                                       draw_sprite(buffer,perguntas[5].o1,10,100); 
                                       draw_sprite(buffer,perguntas[5].o2,10,200); 
                                       draw_sprite(buffer,perguntas[5].o3,10,300); 
                                       draw_sprite(buffer,perguntas[5].o4,10,400);
                                       
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead = 0;
                                                  controla = 1;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }             
                                 }
                                 else if(qpergunta==2){
                                       draw_sprite(buffer,perguntas[6].perg,10,10); 
                                       draw_sprite(buffer,perguntas[6].o1,10,100); 
                                       draw_sprite(buffer,perguntas[6].o2,10,200); 
                                       draw_sprite(buffer,perguntas[6].o3,10,300); 
                                       draw_sprite(buffer,perguntas[6].o4,10,400); 
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead = 0;
                                                  controla = 1;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }    
                                 }
                                 else if(qpergunta==3){
                                       draw_sprite(buffer,perguntas[7].perg,10,10); 
                                       draw_sprite(buffer,perguntas[7].o1,10,100); 
                                       draw_sprite(buffer,perguntas[7].o2,10,200); 
                                       draw_sprite(buffer,perguntas[7].o3,10,300); 
                                       draw_sprite(buffer,perguntas[7].o4,10,400);
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead = 0;
                                                  controla = 1;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }     
                                 }
                                 else if(qpergunta==4){
                                       draw_sprite(buffer,perguntas[8].perg,10,10); 
                                       draw_sprite(buffer,perguntas[8].o1,10,100); 
                                       draw_sprite(buffer,perguntas[8].o2,10,200); 
                                       draw_sprite(buffer,perguntas[8].o3,10,300); 
                                       draw_sprite(buffer,perguntas[8].o4,10,400);
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead = 0;
                                                  controla = 1;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }     
                                  }
                                  else{    
                                    perg =0;
                                    dead=0;
                                    controla=1;
                                    score++;  
                                  }
                            }
                            else if(nl==3){
                                 if(qpergunta==1){
                                       draw_sprite(buffer,perguntas[9].perg,10,10); 
                                       draw_sprite(buffer,perguntas[9].o1,10,100); 
                                       draw_sprite(buffer,perguntas[9].o2,10,200); 
                                       draw_sprite(buffer,perguntas[9].o3,10,300); 
                                       draw_sprite(buffer,perguntas[9].o4,10,400);
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead = 0;
                                                  controla = 1;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }                             
                                 }
                                 else if(qpergunta==2){
                                       draw_sprite(buffer,perguntas[10].perg,10,10); 
                                       draw_sprite(buffer,perguntas[10].o1,10,100); 
                                       draw_sprite(buffer,perguntas[10].o2,10,200); 
                                       draw_sprite(buffer,perguntas[10].o3,10,300); 
                                       draw_sprite(buffer,perguntas[10].o4,10,400); 
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead = 0;
                                                  controla = 1;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }    
                                 }
                                 else if(qpergunta==3){
                                       draw_sprite(buffer,perguntas[11].perg,10,10); 
                                       draw_sprite(buffer,perguntas[11].o1,10,100); 
                                       draw_sprite(buffer,perguntas[11].o2,10,200); 
                                       draw_sprite(buffer,perguntas[11].o3,10,300); 
                                       draw_sprite(buffer,perguntas[11].o4,10,400);
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead = 0;
                                                  controla = 1;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                              
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }     
                                 }
                                 else if(qpergunta==4){
                                       draw_sprite(buffer,perguntas[12].perg,10,10); 
                                       draw_sprite(buffer,perguntas[12].o1,10,100); 
                                       draw_sprite(buffer,perguntas[12].o2,10,200); 
                                       draw_sprite(buffer,perguntas[12].o3,10,300); 
                                       draw_sprite(buffer,perguntas[12].o4,10,400);
                                       if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=85 && mouse_y-17 <=100){
                                               if(mouse_b==1){
                                                  score+=60;                        
                                                  perg = 0;
                                                  qpergunta++;
                                                  dead = 0;
                                                  controla = 1;
                                               }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=185 && mouse_y-17 <=200){
                                           if(mouse_b==1){
                                             life-=10;                        
                                              perg = 0;
                                              qpergunta++;
                                            }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=285 && mouse_y-17 <=300){
                                           if(mouse_b==1){ 
                                             life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }
                                        if(mouse_x-45>=-35 && mouse_x-45 <=55 && mouse_y-17 >=385 && mouse_y-17 <=400){
                                           if(mouse_b==1){
                                            life-=10;                        
                                             perg = 0;
                                             qpergunta++;
                                           }            
                                        }     
                                 }
                                 else{    
                                    perg =0;
                                    dead=0;
                                    controla=1;
                                    score++;  
                                  }
                            }                            
                            textprintf_ex(buffer, font, 150, 13, makecol(255,40,40),-1, "qpergunta: %d", qpergunta);
                             //desenha o mouse na tela 
                            draw_sprite(buffer,cursor,mouse_x-45,mouse_y-17);     
                        }
                    }
                    else{
                         draw_sprite(buffer,win,0,0);     
                    }
                }
                else{
                   //draw_sprite(buffer,nivel[1].nivel,10,10);
                   draw_sprite(screen,dead,50,50);  
                }
            }/*fim da parte principal*/  
        }
        else{
            if(mouse_x-45>=210 && mouse_x-45<=295 && mouse_y-17>=100 && mouse_y-17<=130){                    
                 draw_sprite(buffer,nivel[3].nivel,250,100);
                 if(mouse_b==1){
                   controla =1; 
                   vn=0.10; 
                   qmissao = 0; 
                   nl =1;               
                 }               
            }else
                 draw_sprite(buffer,nivel[0].nivel,250,100); 
       
             if(mouse_x-45>=210 && mouse_x-45<=295 && mouse_y-17>=150 && mouse_y-17<=180){                    
                 draw_sprite(buffer,nivel[4].nivel,250,150);
                 if(mouse_b==1){
                   controla =1;  
                   vn=0.20; 
                  qmissao = 1; 
                  nl =2;              
                 }               
             }else
                 draw_sprite(buffer,nivel[1].nivel,250,150);
             
             if(mouse_x-45>=210 && mouse_x-45<=295 && mouse_y-17>=200 && mouse_y-17<=230) {                   
                 draw_sprite(buffer,nivel[5].nivel,250,200);
                 if(mouse_b==1){
                   controla =1; 
                   vn=0.30;
                   qmissao =2; 
                   nl =3;                
                 }               
             }else
                 draw_sprite(buffer,nivel[2].nivel,250,200);
             draw_sprite(buffer,cursor,mouse_x-45,mouse_y-17);
        }
        
        blit(buffer,screen,0,0,0,0,640,480);
    };
    return 0;   
}END_OF_MAIN();

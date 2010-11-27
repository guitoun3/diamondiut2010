#include "graph.h"


SDL_Surface * loadImage(string filename)
{
     return SDL_DisplayFormat(IMG_Load( filename.c_str()));
}

SDL_Surface * loadImageWithColorKey(string filename, int r, int g, int b)
{
    SDL_Surface* optimizedImage;
    optimizedImage = SDL_DisplayFormat(IMG_Load(filename.c_str()));
    SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY,
            SDL_MapRGB(optimizedImage->format, r, g, b));
    return optimizedImage;
}


void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}

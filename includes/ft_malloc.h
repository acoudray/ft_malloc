/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:26:15 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/19 13:43:32 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC
# define FT_MALLOC
# include <sys/mman.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <pthread.h>
# include <stdio.h>
# include "libft.h"
/*
**	!! LES REGIONS D'ALLOCATIONS DOIVENT ETRE DES MULTIPLES DE SIZEPAGES !!
**	!! SIZEPAGES = 4096 bytes !!
*/

/*
**	TINY EST LA REGION D'ALLOCATION LA PLUS PETITE:
**	1 MB en 32-BIT = 1003520
**	2 MB en 64-BIT = 2002944
**	LA TAILLE DE LA DATA APPARTENANT A CETTE REGION:
**	0 <= DATA <= 496 en 32-BIT
**	0 <= DATA <= 992 en 64-BIT
*/

/*
**	32-BIT
*/

# define TINY_SZ 1003520
# define TINY_PC 496

/*
**	SMALL EST LA DEUXIEME REGION D'ALLOCATION:
**	8 MB en 32-BIT = 8003584
**	16 MB en 64-BIT = 16003072
**	LA TAILLE DE LA DATA APPARTENANT A CETTE REGION EST LA CONTINUITE DE TINY
**	ET EST DELIMITE PAR LA TAILLE DE LA RAM:
**	497 <= DATA <= 15000 || 127000 en 32-BIT < 1GB RAM || >= 1 GB RAM
**	993 <= DATA <= 15000 || 127000 en 64-BIT < 1GB RAM || >= 1 GB RAM
*/

/*
**	32-BIT < 1GB RAM
*/

# define SMALL_SZ 8003584
# define SMALL_PC 127000

/*
**	STRUCT CONTENANT LES META DATA DES ALLOCATIONS:
**	- SIZE CONTIENT LA TAILLE DU BLOCK
**	- FREE EST SET A 1 SI LA ZONE EST LIBRE ET 0 SI ALLOUE
**	- NEXT POINTE SUR LE MAILLON SUIVANT DANS L'ORDRE DE LA MEMOIRE
*/

typedef struct		s_block
{
	char			a;
	size_t			size;
	int				free;
	struct s_block	*next;
}					t_block;

extern t_block	*glob_m;
extern pthread_mutex_t mut;
/*
**	MALLOC FONCTION ALLOUANT SIZE OCTET EN MEMOIRE ET RENVOI LE POINTEUR CORESPONDANT:
**	- APPELLE MEME_INITIALIZE INITIALISE T_BLOCK SI INEXISTANT EST LINK LE POINTER GLOB
**	- APPELLE SEARCH_BLOCK QUI TROUVE LE BLOCK ADEQUAT ET RENVOIE UN POINTEUR DESSUS
**	- APPELLE ALLOC_MEM SI AUCUN BLOCK TROUVE.	
**	- APPELLE BLOCK_SPLIT QUI COUPE EN DEUX LE BLOCK ET POSE UN NOUVEAU META DATA. IL RENVOIE
**	UN POINTEUR SUR LE CHAINONS ALLOUE
**	- RETOURNE L'ADRESSE DU MAILLON + SIZEOF(T_BLOCK)
*/

void	*ft_malloc(size_t size);
void	*ft_new_block(size_t size);
void	*ft_create_block(size_t size, t_block **block);
void	*ft_block_initialize(t_block **block, int maptype, char c);
void	*ft_search_block(size_t size);
void	ft_block_split(void *ptr, size_t size);

/*
**	FREE FONCTION LIBERANT L'ESPACE ALLOUE PAR MALLOC:
**	- APPELLE LA FONCTION SET_FREE MODIFIANT LA META DATA APPARTENANT AU POINTEUR ET SETANT LA MEM
**	- APPELLE MERGE QUI CHECK SI IL N'Y A PAS DE MEMOIRE FRAGMENTE APRES SET_FREE. RENVOIE UN POINTEUR SUR LE MAILLON MERGE
**	- APPELLE DEALLOC_MEM QUI APPLIQUE MUNMAP SI LE BLOCK CORESPOND A UN DES BLOCKS CITE SI DESSUS OU SUPERIEUR ET RELINK LA LISTE
*/

void	ft_free(void *ptr);
void	ft_set_free(t_block *ptr);
// void	merge(t_block *ptr, t_block *tmp);
void	dealloc_mem(t_block *ptr, t_block *tmp);

void    *ft_search_addr(void *ptr);


void	*realloc(void *ptr, size_t size);
void	show_alloc_mem();

#endif
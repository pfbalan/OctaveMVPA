#ifndef lint
static char sccsid[] = "@(#)spm_vol_access.c	2.2 John Ashburner 99/01/15";
#endif

/* matlab independent image access routines;
gateway to routines compiled from spm_vol_utils.c */

#include <math.h>
#include <stdio.h>
#include "spm_vol_access.h"
#include "spm_datatypes.h"

int get_datasize(int type)
{
	if (type == SPM_UNSIGNED_CHAR || type == SPM_SIGNED_CHAR) return(8);
	if (type == SPM_SIGNED_SHORT || type == SPM_SIGNED_SHORT_S) return(16);
	if (type == SPM_UNSIGNED_SHORT || type == SPM_UNSIGNED_SHORT_S) return(16);
	if (type == SPM_SIGNED_INT || type == SPM_SIGNED_INT_S) return(32);
	if (type == SPM_UNSIGNED_INT || type == SPM_UNSIGNED_INT_S) return(32);
	if (type == SPM_FLOAT || type == SPM_FLOAT_S) return(32);
	if (type == SPM_DOUBLE || type == SPM_DOUBLE_S) return(64);
	return(0);
}

int resample(m,vol,out,x,y,z,hold, background)
int m, hold;
double out[], x[], y[], z[], background;
MAPTYPE *vol;
{
	extern void resample_uchar(), resample_short(), resample_int(), resample_float(),
		resample_double(), resample_short_s(), resample_int_s(), resample_float_s(),
		resample_double_s();

	if (vol->dtype == SPM_UNSIGNED_CHAR)
		 resample_uchar(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_CHAR)
		 resample_schar(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_SHORT)
		 resample_short(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_SHORT)
		 resample_ushort(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_INT)
		   resample_int(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_INT)
		   resample_uint(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_FLOAT)
		 resample_float(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_DOUBLE)
		resample_double(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_SHORT_S)
		resample_short_s(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_SHORT_S)
		resample_ushort_s(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_INT_S)
		resample_int_s(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_INT_S)
		resample_uint_s(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_FLOAT_S)
		resample_float_s(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_DOUBLE_S)
		resample_double_s(m,vol->data,out,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else
	{
		(void)fprintf(stderr,"%d: Unknown datatype.\n", vol->dtype);
		return(1);
	}
	return(0);
}

int resample_d(m,vol,out,gradx,grady,gradz,x,y,z, hold, background)
int m, hold;
double out[], gradx[],grady[],gradz[], x[], y[], z[], background;
MAPTYPE *vol;
{
	extern void resample_d_uchar(), resample_d_short(), resample_d_int(), resample_d_float(),
		resample_d_double(), resample_d_short_s(), resample_d_int_s(), resample_d_float_s(),
		resample_d_double_s();

	if (vol->dtype == SPM_UNSIGNED_CHAR)
		 resample_d_uchar(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_CHAR)
		 resample_d_schar(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_SHORT)
		 resample_d_short(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_SHORT)
		 resample_d_ushort(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_INT)
		   resample_d_int(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_INT)
		   resample_d_uint(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_FLOAT)
		 resample_d_float(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_DOUBLE)
		resample_d_double(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_SHORT_S)
		resample_d_short_s(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_SHORT_S)
		resample_d_ushort_s(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_INT_S)
		resample_d_int_s(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_INT_S)
		resample_d_uint_s(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_FLOAT_S)
		resample_d_float_s(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_DOUBLE_S)
		resample_d_double_s(m,vol->data,out,gradx,grady,gradz,x,y,z,vol->dim[0],vol->dim[1],vol->dim[2],
			hold, background, vol->scale,vol->offset);
	else
	{
		(void)fprintf(stderr,"%d: Unknown datatype.\n", vol->dtype);
		return(1);
	}
	return(0);
}

int slice(mat, image, xdim1,ydim1, vol, hold,background)
int ydim1,xdim1, hold;
double image[], mat[], background;
MAPTYPE *vol;
{
	int sts = 1;
	if (vol->dtype == SPM_UNSIGNED_CHAR)
		 sts = slice_uchar(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2],
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_CHAR)
		 sts = slice_schar(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2],
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_SHORT)
		 sts = slice_short(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2],
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_SHORT)
		 sts = slice_ushort(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2],
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_INT)
		 sts = slice_int(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2],
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_INT)
		 sts = slice_uint(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2],
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_FLOAT)
		sts = slice_float(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2],
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_DOUBLE)
		sts = slice_double(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2],
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_SHORT_S)
		sts = slice_short_s(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2], 
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_SHORT_S)
		sts = slice_ushort_s(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2], 
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_SIGNED_INT_S)
		sts = slice_int_s(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2], 
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_UNSIGNED_INT_S)
		sts = slice_uint_s(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2], 
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_FLOAT_S)
		sts = slice_float_s(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2],
			hold,background, vol->scale,vol->offset);
	else if (vol->dtype == SPM_DOUBLE_S)
		sts = slice_double_s(mat, image, xdim1,ydim1, vol->data, vol->dim[0],vol->dim[1],vol->dim[2], 
			hold,background, vol->scale,vol->offset);
	else
	{
		(void)fprintf(stderr,"%d: Unknown datatype.\n", vol->dtype);
		sts = 1;
	}
	return(sts);
}


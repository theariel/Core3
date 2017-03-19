//asm
#define maxTextureCoordinate      2
#define vTextureCoordinateSetMAIN vTextureCoordinateSet0
#define vTextureCoordinateSetDETA vTextureCoordinateSet1
#define vTextureCoordinateSetSPEC vTextureCoordinateSet2

TARGET

#include "vertex_program/modules/registers.inc"


dcl_position0 vPosition
dcl_normal0   vNormal
dcl_color0    vColor0
#include "vertex_program/modules/texture_coordinates.inc"

#include "vertex_program/modules/transform.inc"
#include "vertex_program/modules/lighting_fog_setup.inc"
#include "vertex_program/modules/fog.inc"
#include "vertex_program/modules/c_ambient.inc"
#include "vertex_program/modules/diffuse_specular.inc"

mov oT0, vTextureCoordinateSetMAIN
mov oT1, vTextureCoordinateSetDETA
mov oT2, vTextureCoordinateSetSPEC

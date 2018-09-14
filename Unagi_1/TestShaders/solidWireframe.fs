#version 330



in GS_OUT {
    vec4 pos;
    vec3 col;
    vec3 normal;
    vec2 texCoord;
    vec3 wireframeDist;
} fs_in;

out vec4 FragCol;
 
float edgeFactor()
{
    vec3 d = fwidth(fs_in.wireframeDist);
    vec3 a3 = smoothstep(vec3(0.0), d*0.95, fs_in.wireframeDist);
    return min(min(a3.x, a3.y), a3.z);
}


void main()
{
    
    FragCol = vec4(0.5, 0.5, 0.5, 1.0);
}



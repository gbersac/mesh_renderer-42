#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 Normal;
in vec3 FragPos;

// Ouput data
out vec3 color;

// Values that stay constant for the whole mesh.
uniform sampler2D	TEXTURE_UNIFORM;
uniform vec3		LIGHT_POSITION;
uniform vec3		CAMERA_POSITION;

void main()
{
	// set variables
	vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
	float specularStrength = 0.5f;
	vec3 lightDir = normalize(LIGHT_POSITION - FragPos);
	vec3 norm = normalize(Normal);

	// calculate diffuse light
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	// calculate specular light
	vec3 viewDir = normalize(CAMERA_POSITION - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * lightColor;

    // calculate texture color
    vec3 objectColor = texture(TEXTURE_UNIFORM, UV).rgb;

    // calculate final color
    color = (diffuse + specular) * objectColor;
}

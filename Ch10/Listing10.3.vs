in vec4				vertexPosition;		// The object-space vertex position.
uniform vec4		mvpMatrix[4];		// The model-view-projection matrix.
uniform vec3		lightDirection;		// The object-space light direction.

void main()
{
	float t = (vertexPosition.w < 0.5) ? 1.0 : 0.0;
	vec4 extrudedPosition =
		vec4(vertexPosition.xyz + lightDirection, vertexPosition.w);
	extrudedPosition = vertexPosition - extrudedPosition * t;

	gl_Position = vec4(dot(mvpMatrix[0], extrudedPosition),
			dot(mvpMatrix[1], extrudedPosition),
			dot(mvpMatrix[2], extrudedPosition),
			dot(mvpMatrix[3], extrudedPosition));
}

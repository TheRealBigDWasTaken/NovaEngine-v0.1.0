##### This is the official NovaEngine documentation.



Shoutout to my N100 processor on this laptop, he gave his best to not crash every time I opened VS, 

and shoutout to my friends who had to listen to me crash out because of OpenGL, and GPT because... let's be real how the heck am I supposed to understand GL, 

although I do kinda understand it now.



For an example of (most of) these classes/structs/enums read the main.cpp file from the example project



If you see wierd ### or \*\* in this file when using Notepad, go into view -> Markdown and select formatted



VAO, VBO, IBO are often used to shorten longer words (VAO = VertexArrayObject, VBO = VertexBufferObject, IBO = IndexBufferObject)





###### **Umbrella Headers:**

Core.h, Graphics.h, Math.h (with Physics.h planned for later), and NovaEngine.h are umbrella headers designed to include all the contents of their respective folders.

For Example, Math.h includes Vec2.h, Vec3.h and Transform.h while NovaEngine.h includes everything.

Also, take every comment inside NovaEngine.h with a grain of salt. Desperate times call for desperate measures.





###### **Enum classes:**



**Key:**

The Key enum represents a physical keyboard key on a standard US keyboard, along with additional keys supported by GLFW.



**name		Description**

Key::Space	Represents the Space ( ) key on the keyboard

Key::Apostrophe	Represents the Apostrophe (') key on the keyboard

Key::Comma	Represents the Comma (,) key on the keyboard

Key::Minus	Represents the Minus (-) key on the keyboard

Key::Period	Represents the Period (.) key on the keyboard

Key::Slash	Represents the Slash (/) key on the keyboard



Key::Num0	Represents the 0 key on the keyboard

Key::Num1	Represents the 1 key on the keyboard

Key::Num2	Represents the 2 key on the keyboard

Key::Num3	Represents the 3 key on the keyboard

Key::Num4	Represents the 4 key on the keyboard

Key::Num5	Represents the 5 key on the keyboard

Key::Num6	Represents the 6 key on the keyboard

Key::Num7	Represents the 7 key on the keyboard

Key::Num8	Represents the 8 key on the keyboard

Key::Num9	Represents the 9 key on the keyboard



Key::Semicolon	Represents the Semicolon (;) key on the keyboard

Key::Equal	Represents the Equal (=) key on the keyboard



Key::A		Represents the A key on the keyboard

Key::B		Represents the B key on the keyboard

Key::C		Represents the C key on the keyboard

Key::D		Represents the D key on the keyboard

Key::E		Represents the E key on the keyboard

Key::F		Represents the F key on the keyboard

Key::G		Represents the G key on the keyboard

Key::H		Represents the H key on the keyboard

Key::I		Represents the I key on the keyboard

Key::J		Represents the J key on the keyboard

Key::K		Represents the K key on the keyboard

Key::L		Represents the L key on the keyboard

Key::M		Represents the M key on the keyboard

Key::N		Represents the N key on the keyboard

Key::O		Represents the O key on the keyboard

Key::P		Represents the P key on the keyboard

Key::Q		Represents the Q key on the keyboard

Key::R		Represents the R key on the keyboard

Key::S		Represents the S key on the keyboard

Key::T		Represents the T key on the keyboard

Key::U		Represents the U key on the keyboard

Key::V		Represents the V key on the keyboard

Key::W		Represents the W key on the keyboard

Key::X		Represents the X key on the keyboard

Key::Y		Represents the Y key on the keyboard

Key::Z		Represents the Z key on the keyboard



Key::LeftBracket	Represents the LeftBracket (\[) key on the keyboard

Key::Backslash		Represents the Backslash (\\) key on the keyboard

Key::RightBracket	Represents the RightBracket (]) key on the keyboard

Key::GraveAccent	Represents the GraveAccent (`) key on the keyboard



Key::World1	Represents the first key in the non-US key range

Key::World2	Represents the second key in the non-US key range



Key::Escape	Represents the Escape key on the keyboard

Key::Enter	Represents the Enter key on the keyboard

Key::Tab	Represents the Tab key on the keyboard

Key::Backspace	Represents the Backspace key on the keyboard

Key::Insert	Represents the Insert key on the keyboard

Key::Delete	Represents the Delete key on the keyboard



Key::Right	Represents the Right Arrow key on the keyboard

Key::Left	Represents the Left Arrow key on the keyboard

Key::Down	Represents the Down Arrow key on the keyboard

Key::Up		Represents the Up Arrow key on the keyboard



Key::PageUp	Represents the PageUp key on the keyboard

Key::PageDown	Represents the PageDown key on the keyboard

Key::Home	Represents the Home key on the keyboard

Key::End	Represents the End key on the keyboard



Key::CapsLock		Represents the CapsLock key on the keyboard

Key::ScrollLock		Represents the ScrollLock key on the keyboard

Key::NumLock		Represents the NumLock key on the keyboard

Key::PrintScreen	Represents the PrintScreen key on the keyboard

Key::Pause		Represents the Pause key on the keyboard



Key::F1		Represents the F1 key on the keyboard

Key::F2		Represents the F2 key on the keyboard

Key::F3		Represents the F3 key on the keyboard

Key::F4		Represents the F4 key on the keyboard

Key::F5		Represents the F5 key on the keyboard

Key::F6		Represents the F6 key on the keyboard

Key::F7		Represents the F7 key on the keyboard

Key::F8		Represents the F8 key on the keyboard

Key::F9		Represents the F9 key on the keyboard

Key::F10	Represents the F10 key on the keyboard

Key::F11	Represents the F11 key on the keyboard

Key::F12	Represents the F12 key on the keyboard

Key::F13	Represents the F13 key on the keyboard

Key::F14	Represents the F14 key on the keyboard

Key::F15	Represents the F15 key on the keyboard

Key::F16	Represents the F16 key on the keyboard

Key::F17	Represents the F17 key on the keyboard

Key::F18	Represents the F18 key on the keyboard

Key::F19	Represents the F19 key on the keyboard

Key::F20	Represents the F20 key on the keyboard

Key::F21	Represents the F21 key on the keyboard

Key::F22	Represents the F22 key on the keyboard

Key::F23	Represents the F23 key on the keyboard

Key::F24	Represents the F24 key on the keyboard

Key::F25	Represents the F25 key on the keyboard



Key::KP0	Represents the 0 key on the numpad

Key::KP1	Represents the 1 key on the numpad

Key::KP2	Represents the 2 key on the numpad

Key::KP3	Represents the 3 key on the numpad

Key::KP4	Represents the 4 key on the numpad

Key::KP5	Represents the 5 key on the numpad

Key::KP6	Represents the 6 key on the numpad

Key::KP7	Represents the 7 key on the numpad

Key::KP8	Represents the 8 key on the numpad

Key::KP9	Represents the 9 key on the numpad



Key::KPDecimal	Represents the Decimal key on the numpad

Key::KPDivide	Represents the Divide key on the numpad

Key::KPMultiply	Represents the Multiply key on the numpad

Key::KPSubtract	Represents the Subtract key on the numpad

Key::KPAdd	Represents the Add key on the numpad

Key::KPEnter	Represents the Enter key on the numpad

Key::KPEqual	Represents the Equal key on the numpad



Key::LeftShift		Represents the LeftShift key on the keyboard

Key::LeftControl	Represents the LeftControl key on the keyboard

Key::LeftAlt		Represents the LeftAlt key on the keyboard

Key::LeftSuper		Represents the Left Super (Windows/Command) key on the keyboard



Key::RightShift		Represents the RightShift key on the keyboard

Key::RightControl	Represents the RightControl key on the keyboard

Key::RightAlt		Represents the RightAlt key on the keyboard

Key::RightSuper		Represents the Right Super (Windows/Command) key on the keyboard



Key::Menu		Represents the Context menu key on the keyboard





**MouseButton:**



The MouseButton enum represents a button on a mouse. Some mice might not have certain buttons



**name			Description**

MouseButton::Left	Represents the Left Mouse Button

MouseButton::Right	Represents the Right Mouse Button

MouseButton::Middle	Represents the Middle Mouse Button (clicking the scroll wheel)

MouseButton::Button4	Represents the fourth Mouse Button (may not be present on every mouse)

MouseButton::Button5	Represents the fifth Mouse Button (may not be present on every mouse)

MouseButton::Button6	Represents the sixth Mouse Button (may not be present on every mouse)

MouseButton::Button7	Represents the seventh Mouse Button (may not be present on every mouse)

MouseButton::Button8	Represents the eighth Mouse Button (may not be present on every mouse)



**VertexSemantic:**



The VertexSemantic enum is used to specify what the bytes (when using VertexLayout) represent.



**name		Description**

Position	Tells the VertexLayout that these bytes represent the Position

Normal		Tells the VertexLayout that these bytes represent a Normal

UV		Tells the VertexLayout that these bytes represent the UV

Color		Tells the VertexLayout that these bytes represent a color, RGB or RGBA is determined with the VertexLayout



**VertexDataType:**



The VertexDataType enum is used to specify how the bytes are stored (int, float, unsigned int, etc)



**name		Description**

Float		Tells the VertexLayout that these bytes are stored as 32-bit floats

Int		Tells the VertexLayout that these bytes are stored as 32-bit ints

UnsignedInt	Tells the VertexLayout that these bytes are stored as 32-bit unsigned ints

UnsignedByte	Tells the VertexLayout that these bytes are stored as 8-bit bytes



**VertexAttributeInterpretation:**



Specifies how the vertex attribute data should be interpreted by the vertex shader.



* FloatingPoint: The data is passed to the shader as floating-point values. Uses glVertexAttribPointer().
* Integer: The data is passed to the shader as integer values. Uses glVertexAttribIPointer().

Note: This is independent of VertexDataType. Integer storage types can also be interpreted as floating-point values, for example when using normalized unsigned bytes for colors.



**name		Description**

FloatingPoint	Used for if this attribute is stored as a float

Integer		Used for if this attribute is stored as an integer (int, unsigned int, byte)





###### **Non-class helper function**



**Name				Parameters	Return Value	Parameter Description**

GetVertexDataTypeSize		VertexDataType	uint32\_t	The type, the size of is being queried

GetMinVertexElementCount	VertexSemantic	uint32\_t	The type, the minimum required count is being queried

GetExpectedVertexElementCount 	VertexSemantic	uint32\_t	The type, the maximum allowed count is being queried

VertexDataTypeToOpenGL		VertexDataType	GLenum		Returns the GLenum variant of the VertexDataType



**Name 				Function Description**

GetVertexDataTypeSize		Returns the size of what the parameter represent

GetMinVertexElementCount	Returns the minimum required count for a Semantic to be valid

GetExpectedVertexElementCount	Returns the maximum allowed count for a Semantic to be valid



###### **Vec2 class**



The Vec2 class is just a basic 2-component vector (x, y), with helper functions like Normalize(), Length() or dot product calculations.



**Variables:**



**Name		Type		Access	Static	Description \& use**

x		float		public	No	Stores the x component of the vector

y		float		public 	No	Stores the y component of the vector

**Functions:**



**Name		Parameters	Return Value	Parameter Description**

Constructor	void		/		/

Constructor	float x		/		The initial x component of the vector

&#x09;	float y				The initial y component of the vector

operator+	const Vec2\&	Vec2		The other vector to add to the current vector

operator-	const Vec2\& 	Vec2		The other vector to subtract from the current vector

operator\*	float scalar	Vec2		The scalar by which both vector components are multiplied

operator/	float scalar	Vec2		The scalar by which both vector components are divided

Length		void		float		/

LengthSquared	void		float		/

Normalized	void		Vec2		/

Normalize	void		void		/

Distance	const Vec2\& other	float	The other vector whose distance from the current vector is calculated

Dot		const Vec2\& other	float	The other vector used to calculate the dot product



**Name 		Function Description**

Constructor	Constructs a Vector with the specified x and y values or 0.0f, 0.0f if none are specified

operator+	Performs vector addition by adding the corresponding components of both vectors

operator-	Performs vector subtraction by subtracting the corresponding components of the other vector

operator\*	Performs scalar multiplication by multiplying both vector components by the specified scalar.

operator/	Performs scalar division by dividing both vector components by the specified scalar

Length		Returns the Vector's magnitude

LengthSquared	Returns the Vector's magnitude squared (avoiding the square root calculation)

Normalized	Returns a normalized copy of the vector

Normalize	Normalizes the vector object itself

Distance	Returns the distance that represents the distance between the 2

Dot		Returns the dot product of the current vector and the specified vector





###### **Vec3 class**



The Vec3 class represents a basic three-component vector (x, y, z) and provides helper functions such as Normalize(), Length(), and dot product calculations.



**Variables:**



**Name		Type		Access	Static	Description \& use**

x		float		public	No	Stores the x component of the vector

y		float		public 	No	Stores the y component of the vector

z		float		public	No	Stores the z component of the vector



The next ones are static presets.

One		const Vec3	public	Yes	Vector with the preset: x =  1.0f; y =  1.0f; z =  1.0f

Zero		const Vec3	public	Yes	Vector with the preset: x =  0.0f; y =  0.0f; z =  0.0f

Up		const Vec3	public	Yes	Vector with the preset: x =  0.0f; y =  1.0f; z =  0.0f

Down		const Vec3	public	Yes	Vector with the preset: x =  0.0f; y = -1.0f; z =  0.0f

Right		const Vec3	public	Yes	Vector with the preset: x =  1.0f; y =  0.0f; z =  0.0f

Left		const Vec3	public	Yes	Vector with the preset: x = -1.0f; y =  0.0f; z =  0.0f

Forward		const Vec3	public	Yes	Vector with the preset: x =  0.0f; y =  0.0f; z =  1.0f

Back		const Vec3	public	Yes	Vector with the preset: x =  0.0f; y =  0.0f; z = -1.0f



**Name		Parameters	Return Value	Parameter Description**

Constructor	void		/		/

Constructor	float x		/		The initial x component of the vector

&#x09;	float y				The initial y component of the vector

&#x09;	float z				The initial z component of the vector

Constructor	const Vec2\& xy	/		The initial x and y components of the vector

&#x09;	float z				The initial z component of the vector

operator+	const Vec3\&	Vec3		The other vector to add to the current vector

operator-	const Vec3\& 	Vec3		The other vector to subtract from the current vector

operator\*	float scalar	Vec3		The scalar by which both vector components are multiplied

operator/	float scalar	Vec3		The scalar by which both vector components are divided

Length		void		float		/

LengthSquared	void		float		/

Normalized	void		Vec3		/

Normalize	void		void		/

Distance	const Vec3\& other	float	The other vector whose distance from the current vector is calculated

Dot		const Vec3\& other	float	The other vector used to calculate the dot product

Cross		const Vec3\& other	Vec3	The other vector used to calculate the cross product



**Name 		Function Description**

Constructor	Constructs a Vector with the specified x, y and z values or 0.0f, 0.0f, 0.0f if none are specified

operator+	Performs vector addition by adding the corresponding components of both vectors

operator-	Performs vector subtraction by subtracting the corresponding components of the other vector

operator\*	Performs scalar multiplication by multiplying both vector components by the specified scalar

operator/	Performs scalar division by dividing both vector components by the specified scalar

Length		Returns the Vector's magnitude

LengthSquared	Returns the Vector's magnitude squared (avoiding the square root calculation)

Normalized	Returns a normalized copy of the vector

Normalize	Normalizes the vector object itself

Distance	Returns the distance that represents the distance between the 2

Dot		Returns the dot product of the current vector and the specified vector

Cross		Returns the cross product of the current vector and the specified vector





###### **Transform class**



The Transform class stores an object's position, rotation and scale.

The transformation matrix is only generated when GetMatrix() is called. As a result, the matrix is not stored.

This is the first class that depends on GLM.



**Variables:**



**Name		Type		Access	Static	Description \& use**

Position	Vec3		public	No	The position of the object stored as a Vec3

Rotation	glm::quat	public	No	The rotation of the object stored as a quaternion (glm:quat)

Scale		Vec3		public	No	The scale of the object stored as a Vec3



**Functions:**



**Name		Parameters	Return Value	Parameter Description**

Constructor	void		/		/

GetMatrix	void		glm::mat4	/

Rotate		const Vec3\& axis void		Axis around which the object rotates

&#x09;	float angleDegrees		The rotation angle



**Name 		Function Description**

Constructor	Constructs a default Transform with the following values: Position = (0.0f, 0.0f, 0.0f); Rotation = Identity; Scale = (1.0f, 1.0f, 1.0f)

GetMatrix	Returns the transformation matrix used for rendering the object. The object's initial vertices are transformed using this matrix in the shader

Rotate		Rotates the object around the specified axis by the specified angle





###### **Window class**



The Window class manages the GLFW window and provides helper functions for window management, OpenGL initialization, and frame handling.



**Variables:**



**Name		Type		Access	Static	Description \& use**

m\_width		int		private	No	Stores the window's width

m\_height	int		private	No	Stores the window's height

m\_windowName	std::string	private	No	Stores the window's title

m\_window	GLFWwindow\*	private No	Pointer to the underlying GLFW window



**Functions:**



**Name		Parameters	Return Value	Parameter Description**

SetWidth	int width	void		The new width to set for the window

SetHeight	int height	void		The new height to set for the window

GetWidth	void		int		/

GetHeight	void		int		/

SetViewPort	int x		void		Sets the horizontal starting position of the viewport rectangle

&#x09;	int y				Sets the vertical starting position of the viewport rectangle

&#x09;	int width			Sets the width of the viewport rectangle

&#x09;	int height			Sets the height of the viewport rectangle

Exit		void		void		/

Constructor	int width	/		The target width of the window

&#x09;	int height			The target width of the window

&#x09;	std::string\& windowName		The title displayed in the window's title bar

Initialize	void		int		/

IsOpen		void		bool		/

GetNativeWindow	void		GLFWwindow\*	/

Terminate	void		void		/

EndFrame	void		void		/

PollEvents	void		void		/

Clear		float r		void		The red component of the clearing color (between 0.0f and 1.0f)

&#x09;	float g				The green component of the clearing color (between 0.0f and 1.0f)

&#x09;	float b				The blue component of the clearing color (between 0.0f and 1.0f)

&#x09;	float a				The alpha (transparency) component of the clearing color (between 0.0f and 1.0f) (why did I include this??)



**Name 		Function Description**

SetWidth	Sets the window width to the specified value

SetHeight	Sets the window height to the specified value

GetWidth	Returns the window's current width (m\_width)

GetHeight	Returns the window's current height (m\_height)

SetViewPort	Sets the Drawing area using the rectangle defined by the parameters

Exit		Tells the engine that the window should close

Constructor	Prepares the internal variables but DOES NOT CREATE THE WINDOW, to facilitate error handling the window creation happens in Initialize()

Initialize	Creates the GLFW window and returns an integer indicating the result: 1 = success, -1 = window creation failed, -2 = GLAD failed to load

IsOpen		Returns whether the window is still open

GetNativeWindow	Returns a pointer to the underlying GLFWwindow owned by the window object

Terminate	Destroys the window and terminates GLFW

EndFrame	Swapps front and back buffers

PollEvents	Polls for and processes window events.

Clear		Sets the clearing color and clears both the color and depth buffers





###### **Input class:**



The Input class is a static class used to check for user input using the 'IsKeyPressed' or 'IsMouseButtonPressed' functions.

The class doesn't own the currently bound GLFW window, only a reference to it.

For the Input class to work it has to be bound with a window, and it uses a GLFWwindow\* as a parameter so when binding to a Window-object, use the window's 'GetNativeWindow' function. All functions are static too.



**Variables:**



**Name		Type		Access	Static	Description \& use**

m\_Window	GLFWwindow\*	private	Yes	The currently bound window, on which the input is checked



**Functions:**



**Name			Parameters		Return Value	Parameter Description**

Bind			GLFWwindow\* window	/		The window being bound to check input on in the future

IsKeyPressed		(enum)Key key		bool		The selected key to check if it's held down

IsMouseButtonPressed   (enum)MouseButton button bool		The selected MouseButton to check if it's held down



**Name 			Function Description**

Bind			Static function that binds the specified window to check input on in the future

IsKeyPressed		Static function that checks if the specified key is currently held down on the bound window.

&#x09;		If no window is bound, it will always return false

IsMouseButtonPressed	Static function that checks if the specified mouse button is currently held down on the bound window.

&#x09;		If no window is bound, it will always return false



###### **DeltaTime class:**



The DeltaTime class is a static class used to determine the time between two consecutive frames.

Because of the design the DeltaTime has to be manually updated.

The DeltaTime for each frame is capped at 100ms so if a massive lag spike happens, the player doesn't teleport.

All functions are static.



**Variables:**



**Name		Type		Access	Static	Description \& use**

m\_LastTime	double		private	Yes	Used to calculate difference between this frame and the previous

m\_DeltaTime	float		private	Yes	The stored DeltaTime, can be accessed with 'DeltaTime::Get()'



**Functions:**



**Name		Parameters	Return Value	Parameter Description**

Update		void		void		/

Get		void		float		/



**Name 		Function Description**

Update		Updates the m\_DeltaTime variable, caps the DeltaTime at 0.1f, recommended to be called at a consistent point in the game loop

Get		Returns the currently stored delta time





###### **VertexBuffer class:**



This class is not supposed to be used by the user, it's for other classes. In the documentation VBO might be used to abbreviate the name.

This class is made to upload data to the GPU's memory.



**Variables:**



**Name	Type	Access	Static	Description \& use**

m\_ID	GLuint	private	No	The ID of the uploaded data, to modify/delete if necessary



**Functions:**



**Name		Parameters		Return Value	Parameter Description**

Constructor	const void\* vertices	/		The pointer to the data wished to upload

&#x09;	unsigned int size			How many bytes should be uploaded. Do not make this bigger than the Array is,

&#x09;						because garbage data can be copied and it may cause a crash

Destructor	void			/		/

Bind		void			void		/

Unbind		void			void		/



**Name 		Function Description**

Constructor	Uploads the data to the GPU's memory.

&#x09;	Uses GL\_STATIC\_DRAW in the 'glBufferData' function, because the data is intended to remain unchanged

Destructor	Frees the memory on the GPU and deletes the object

Bind		Binds the VBO

Unbind		Binds the VBO with id 0



###### **VertexElement struct:**



This should only be used by the engine itself, it stores everything needed to use glVertexAttribPointer

(or glVertexAttribIPointer if VertexAttributeInterpretation is Integer).



**Variables:**



**Name		Type				Access	Static	Description \& use**

semantic	VertexSemantic			public	No	What the attribute represents, used to figure out location for shader

semanticIndex	uint32\_t			public	No	Currently unused variable to potentially support multiple UVs

type		VertexDataType			public	No	How will the data be stored

interpretation	VertexAttributeInterpretation	public	No	Used to figure out if it should use glVertexAttribIPointer of glVertexAttribPointer

count		uint32\_t			public	No	How many of the semantic are there

normalized	bool				public	No	Are the values normalized

offset		uint32\_t			public	No	How many bytes into the Vertex is this attribute

size		uint32\_t			public	No	The total size of this attribute in bytes, 													calculated as count multiplied by the size of its data type

**Functions:**



**Name		Parameters					Parameter Description**

Constructor	VertexSemantic semantic				What the attribute represents, used to figure out location for shader

&#x09;	uint32\_t semanticIndex				Currently unused variable to potentially support multiple UVs

&#x09;	VertexDataType type				how the data is stored

&#x09;	VertexAttributeInterpretation interpretation	Used to figure out if it should use glVertexAttribIPointer of glVertexAttribPointer

&#x09;	uint32\_t count					How many of the semantic are there

&#x09;	bool normalized					Are the values normalized,

&#x09;							Not useful when using Integer interpretation becaues normalization is skipped

&#x09;	uint32\_t offset					How many bytes into the Vertex is this attribute



**Name 		Function Description**

Constructor	Initializes the variables with values of the parameters of same name, size is constructed with count and type



###### **VertexLayout class:**



This is designed to make custom Vertex layouts easier to configure (without having to use glVertexAttribPointer).

It can be templated to use floats, bytes, int or unsigned int.



**Variables:**



**Name		Type				Access	Static	Description \& use**

m\_Elements	std::vector<VertexElement>	private	No	Stores all of the attributes, for other classes like Mesh to use

m\_Stride	uint32\_t			private	No	Stores the total size (in bytes) of one Vertex



**Functions:**



**Name			Parameters		Return value			Parameter Description**

Constructor		void			/				/

GetElements		void			const vector<VertexElement>\&	/

GetStride		void			uint32\_t			/

IsValidElement		const VertexElement\& e	bool			What element to check

HasSemantic		VertexSemantic semantic	bool			Checks whether the elements vector has an Element with that semantic

Push<float>		VertexSemantic semantic	void			What should the bytes represent

&#x09;		uint32\_t count					How many in each vertex should there be

&#x09;		bool normalized = false				Are the values normalized (doesn't affect if

&#x09;								VertexAttributeInterpretation is Integer, defaults to false)

&#x09;VertexAttributeInterpretation interpretation  			Should be Integer if the value is an integer

&#x09;= VertexAttributeInterpretation::FloatingPoint			(only set if using Push<unsigned int>,Push<unsigned char>,Push<int>)

&#x09;		uint32\_t semanticIndex = 0			Unused system to support multiple UVs

Push<unsigned int>	VertexSemantic semantic	void			What should the bytes represent

&#x09;		uint32\_t count					How many in each vertex should there be

&#x09;		bool normalized = false				Are the values normalized (doesn't affect if

&#x09;								VertexAttributeInterpretation is Integer, defaults to false)

&#x09;VertexAttributeInterpretation interpretation  			Should be Integer if the value is an integer

&#x09;= VertexAttributeInterpretation::FloatingPoint			(only set if using Push<unsigned int>,Push<unsigned char>,Push<int>)

&#x09;		uint32\_t semanticIndex = 0			Unused system to support multiple UVs

Push<unsigned char>	VertexSemantic semantic	void			What should the bytes represent

&#x09;		uint32\_t count					How many in each vertex should there be

&#x09;		bool normalized = false				Are the values normalized (doesn't affect if

&#x09;								VertexAttributeInterpretation is Integer, defaults to false)

&#x09;VertexAttributeInterpretation interpretation  			Should be Integer if the value is an integer

&#x09;= VertexAttributeInterpretation::FloatingPoint			(only set if using Push<unsigned int>,Push<unsigned char>,Push<int>)

&#x09;		uint32\_t semanticIndex = 0			Unused system to support multiple UVs

Push<int>		VertexSemantic semantic	void			What should the bytes represent

&#x09;		uint32\_t count					How many in each vertex should there be

&#x09;		bool normalized = false				Are the values normalized (doesn't affect if

&#x09;								VertexAttributeInterpretation is Integer, defaults to false)

&#x09;VertexAttributeInterpretation interpretation  			Should be Integer if the value is an integer

&#x09;= VertexAttributeInterpretation::FloatingPoint			(only set if using Push<unsigned int>,Push<unsigned char>,Push<int>)

&#x09;		uint32\_t semanticIndex = 0			Unused system to support multiple UVs



**Name 			Function Description**

Constructor		Creates a default object, with an empty vector and a 0 stride

GetElements		Returns the internal vector of Elements

GetStride		Returns the internal stride

IsValidElement		Returns whether the VertexElement is valid (if semantic count's are right like a 1d pos is not allowed)

HasSemantic		Returns if the Layout has an element with the specific semantic (used for Mesh, because a layout without pos is useless)

Push<float>		Adds a new element to the vector, with the <float> it is implied that the bytes are stored as floats

Push<unsigned int>	Adds a new element to the vector, with the <unsigned int> it is implied that the bytes are stored as unsigned ints

Push<unsigned char>	Adds a new element to the vector, with the <unsigned char> it is implied that the bytes are stored as unsigned chars

Push<int>		Adds a new element to the vector, with the <int> it is implied that the bytes are stored as int



###### **VertexArray class:**



This class is internal to the engine and should not be used directly by the user.



The VAO object is used to remember what the vertices should represent and what VBO was bound when sending.

If the VAO is bound, binding a VBO will make the VAO remember it, same for 'glVertexAttribPointer' calls.

When the VAO gets bound, and a Draw call is issued (in plain gl), The attributes the VAO remembers will be used for drawing.



**Variables:**



**Name	Type	Access	Static	Description \& use**

m\_ID	GLuint	private	No	Represents the ID of the Vertex Array, used to get access to the VAO in the GPU



**Functions:**



**Name		Parameters	Return value	Parameter Description**

Constructor	void		/		The endless void in my eyes after realizing I spend 4 months making

&#x09;					something I don't remember because I suffered too much with OpenGL...

Destructor	void		/		/

Bind		void		void		/

Unbind		void		void		/





**Name 		Function Description**

Constructor	Constructs and Binds a new VertexArray

Destructor	Frees the VertexArray from the GPUs memory

Bind		Binds the VertexArray, to be used for drawing

Unbind		Unbinds the VertexArray, do not draw when VAO is unbound



###### **IndexBuffer class:**



This class is internal to the engine and should not be used directly by the user.

The IBO is used to save on memory, by defining which Vertex to use.

This can save on memory when having duplicate vertices.



**Variables:**



**Name	Type	Access	Static	Description \& use**

m\_ID	GLuint	private	No	Represents the ID of the IndexBuffer, used to get access to the IndexBuffer in the GPU



**Functions:**



**Name		Parameters			Return value	Parameter Description**

Constructor	const unsigned int\* indices	/		The pointer to the first unsigned int of the array, (you can just pass in the array name).

&#x09;	unsigned int count				How many unsigned ints are in the array, THE SIZE IS NOT IN BYTES

Destructor	void				/		/

Bind		void				void		/

Unbind		void				void		/





**Name 		Function Description**

Constructor	Constructs a new IBO with the data given and doesn't bind it (because of the VAOs element buffer association).

Destructor	Frees the IBO from the GPUs memory

Bind		Binds the IBO

Unbind		Unbinds the IBO



###### **Shader class:**



This class is used to determine where vertices will end up and what color they will have.

This will in later versions be automated but some example shaders will be underneath all the function descriptions.

The shaders will be created at runtime (because of design) so the shaders should be relative to the exe, make sure to take into acount when moving the exe file.



**Variables:**



**Name	Type		Access	Static	Description \& use**

m\_ID	unsigned int	private	No	The program ID to access the shader



**Functions:**



**Name		Parameters			Return value	Parameter Description**

Constructor	const std::string\& vertexPath	/		The path, relative to the exe, where the vertexShader code is

&#x09;	const std::string\& fragmentPath	/		The path, relative to the exe, where the fragmentShader code is

Destructor	void				/		/

Use		void				void		/

SetUniform3f	const std::string\& name		void		Where the attributes will be sent (location but with name)

&#x09;	float x						What the first attribute's value is

&#x09;	float y						What the second attribute's value is

&#x09;	float z						What the third attribute's value is

SetUniformMat4	const std::string\& name		void		Where the attributes will be sent (location but with name)

&#x09;	const glm::mat4\& matrix				The matrix that will be uploaded to the shader

SetUniform1i	const std::string\& name		void		Where the attributes will be sent (location but with name)

&#x09;	int value					The value that will be uploaded to the shader



**Name 		Function Description**

Constructor	loads, compiles, links a vertex and a fragment shader from filepaths.

&#x09;	Throws an std::runtime\_error if shaders could not be opened, compilation or linking fails

Destructor	Deletes the program from the GPUs memory

Use		Make this shader the one getting the information, being used to draw

SetUniform3f	Sends a 3-component float vector to a location determined by a name. If no vec3 of that name is requested in the shader code, nothing gets sent.

&#x09;	(example: 3.)

SetUniformMat4	Sends a 4 by 4 matrix to a location determined by a name. If no mat4 of that name is requested in the shader code, nothing gets sent.

&#x09;	(example: 4.)

SetUniform1i	Sends 1 integer value to a location determined by a name. If no int of that name is requested in the shader code, nothing gets sent.

&#x09;	(example: 5.)



**Examples:**



1. A vertex shader

\#version 330 core



layout(location = 0) in vec2 aPos; // location 0 is the Position attribute assigned by Mesh, it always is there

&#x09;			   // location 1 is the Normal attribute assigned by Mesh, it always is there

layout(location = 2) in vec2 aUV;  // location 2 is the UV attribute assigned by Mesh, it always is there

&#x09;			   // location 3 is the Color attribute assigned by Mesh, it always is there

uniform mat4 uTransform;	// these 3 objects (uTransform, uView, uProjection) are supplied by the Renderer and are used to find the vertex final 

uniform mat4 uView;

uniform mat4 uProjection;



out vec2 vUV;	// for the fragment shader



void main(){

&#x09;gl\_Position = uProjection \* uView \* uTransform \* vec4(aPos, 0, 1); // calculate the final position using the position attribute and the camera

&#x09;vUV = aUV;	// the attribute being sent to the fragment is the one given by the attribute

}



2\. A fragment shader

\#version 330 core



uniform sampler2D uTexture;	//The texture sent by the renderer if the GameObject has a texture

uniform vec3 uColor;	// The color (White in case the GameObject has a texture)



out vec4 FragColor;	// The end color for the pixel



in vec2 vUV;	// we ask to get the UV we sent from the vertex shader



void main()

{

&#x20;   FragColor = texture(uTexture, vUV) \* vec4(uColor, 1.0);	//calculate the color of the pixel

}



3\. SetUniform3f("uColor", 1.0f, 1.0f, 1.0f);

uniform vec3 uColor // we ask for a 3-component float vector called 'uColor'



4\. SetUniformMat4("uMatrix")

uniform mat4 uMatrix // we ask for a 4 by 4 matrix called 'uMatrix'



5\. SetUniform1i("uInt", 1.2f)

uniform int uInt // we ask for one int called 'uInt'





###### **Texture class:**



The Texture class is used to render images and textures, it cannot be used on its own, it has to be used with a GameObject (bound to the gameobject and the renderer does the job).

Alpha blending isf not supported for some reason (I'll fix it I promise... in 5 months) and Pixel art doesn't have a good contrast so everything blends together (this should also be fixed soon... the same soon as GTA 6)



**Variables:**



**Name		Type	Access	Static	Description \& use**

m\_ID		GLuint	private	No	Represents the ID given by GL, used to access the texture on the GPUs memory

m\_width		int	private No	Stores the image's width

m\_height	int	private No	Stores the image's height

m\_channels	int	private	No	Stores how many color channels the image has (3 = RGB, 4 = RGBA)



**Functions:**



**Name		Parameters			Return value	Parameter Description**

Constructor	const std::string\& path		/		The exe-relative filepath to the texture, because it is made at runtime, 

&#x09;							there might be bugs when the texture is not present relative to the exe

Constructor	unsigned int width		/		The width of the image wanting to be created

&#x09;	unsigned int height				The height of the image wanting to be created

&#x09;	const unsigned char\* data			A pointer to the raw data bytes in RGBA of how the targeted image will look like

Destructor	void				/		

Bind		unsigned int slot = 0		void		I have no Idea why the heck I added that, 

&#x09;							that is a side effect of being traumatized by OpenGL and letting chatGPT explain the gameplan

Unbind		void				void		/



**Name 			Function Description**

Constructor (with path)	Creates and binds a texture from the filepath and uploads it to the GPU

Constructor (with data)	Creates and binds a texture from the data (in RGBA) and uploads it to the GPU, 

&#x09;		this was mainly made to initialize the default texture for the Renderer class

Destructor		Deletes the texture from the GPUs memory

Bind			Binds the texture for drawing

Unbind			Unbinds the texture





###### **Camera class:**



The camera class allows to get a different perspective, fov, position.

After changing a setting like fov (aspect), the projection matrix has to be updated before the effects apply.

After changing a setting like the position, the ViewMatrix has to be updated before the effects apply.

No rotation can be applied YET... so the default rotation is looking towards Z-



**Variables:**



**Name			Type		Access	Static	Description \& use**

m\_FOV			float		private	No	Stores the FOV in degrees, represents the Field Of View

m\_AspectRatio		float		private	No	Stores the aspect ratio

m\_NearClip		float		private	No	Stores the near clip, how close an object can be before not being rendered, 

&#x09;						prevents seeing the interior of objects

m\_FarClip		float		private	No	Stores the far clip, how far an object can be before not being rendered, 

&#x09;						prevents objects from being drawn too far away

m\_Position		Vec3		private	No	Stores the position in the worldspace of the camera

m\_ViewMatrix		glm::mat4	private	No	Stores the ViewMatrix, when multiplied with a vertex's position, it applies the effects like position

&#x09;						It stores *where* to look

m\_ProjectionMatrix	glm::mat4	private	No	Stores the ProjectionMatrix, when multiplied with the ViewMatrix multiplied with the vertex position, 

&#x09;						it applies the effects like FOV. It stores *how* the camera looks

**Functions:**



**Name			Parameters		Return value	Parameter Description**

Constructor		float fov		/		The fov for the new camera object

&#x09;		float aspectRatio			The aspectRatio for the new camera object

&#x09;		float nearClip				The near clip for the new camera object

&#x09;		float farClip				The far clip for the new camera object

GetViewMatrix		void			const glm::mat4	/

GetProjectionMatrix	void			const glm::mat4	/

GetPosition		void			const Vec3\&	/

SetPosition		const Vec3\& pos		void		The position where the camera will be teleported after calling UpdateViewMatrix

SetFOV			float fov		void		The FOV the camera will adopt after calling UpdateProjectionMatrix

UpdateViewMatrix	void			void		/

UpdateProjectionMatrix	void			void		/



**Name 			Function Description**

Constructor		Constructs a new camera with the parameters

GetViewMatrix		Returns the View Matrix 

GetProjectionMatrix	Returns the Projection Matrix

GetPosition		Returns a Vec3 containing the camera's position

SetPosition		Sets the position of the camera using a Vec3

SetFOV			Sets the FOV from a float (FOV in degrees)

UpdateViewMatrix	Updates the View Matrix from the attributes stored internally, to use after modifying the Position

UpdateProjectionMatrix	Updates the Projection Matrix from the attributes stored internally, to use after modifying the FOV, the aspectRatio, the nearClip, the farClip





###### **Mesh class:**



Groups together a VAO, VBO, IBO and VertexLayout to make everything easier for the user and engine to manage in general.



**Variables:**



**Name		Type		Access	Static	Description \& use**

m\_VAO		VertexArray	private	No	The VAO that remembers how the Bytes are stored/ what they represent

m\_VBO		VertexBuffer	private	No	The VBO storing all the vertices for the model

m\_IBO		IndexBuffer	private	No	The IBO to tell what vertices to use for rendering

m\_indexCount	unsigned int	private	No	How many indices were given at creation, used for telling gl how many indices of the IBO it should use



**Functions:**



**Name			 Parameters			Return value	Parameter Description**

Constructor		 const void\* vertices		/		A pointer to the raw bytes of the vertices

&#x09;		 unsigned int vertexSize			How many bytes of the vertices Array should be used. Do not make this bigger than the Array is

&#x09;		 const unsigned int\* indices			A pointer to the indices, to tell the engine what vertices should be used for each triangle

&#x09;		 unsigned int indexCount			How many unsigned ints are in the indices array, THE SIZE IS NOT IN BYTES

&#x09;		 const VertexLayout\& vertexLayout		How the vertices are stored in memory

Draw			 void				void		/

Bind			 void				void		/

VertexSemanticToLocation VertexSemantic semantic	GLuint		What semantic the shader location is wished to know



**Name	 		 Function Description**

Constructor		 Constructs everything so that Draw calls are possible immediately

Draw			 Binds the mesh's VAO and draws the mesh

Bind			 Binds the mesh's VAO

VertexSemanticToLocation Returns the location where the corresponding semantic has to be sent when sending to the shader



###### **RenderCommand struct:**



The RenderCommand struct is internal to the engine and should not be used by the user.

It is used by the renderer to remember what objects to render and how, by storing a mesh, texture, shader, transform and a color.

It doesn't own ANYTHING except the color, it only stored pointers to these objects



**Variables:**



**Name		Type			Access	Static	Description \& use**

meshPtr		const Mesh\*		public	No	Stores a reference to the GameObject's mesh

shaderPtr	const Shader\*		public	No	Stores a reference to the GameObject's shader

transformPtr	const Transform\*	public	No	Stores a reference to the GameObject's transform

texturePtr	const Texture\*		public	No	Stores a reference to the GameObject's texture

color		Vec3			public	No	Stores the GameObject's Color





###### **GameObject class:**



The GameObject class groups a mesh, shader, transform, texture and color for ease of use. A GameObject is required for the Renderer to render.

It only owns the transform and the color, the rest are just references (pointers).

The Mesh, Texture, Shader have to stay alive during the entire duration of the GameObjects existance.

When using The Texture variant of the constructor, the color is defaulted to white (#FFFFFF)



**Variables:**



**Name		Type		Access	Static	Description \& use**

transform	Transform	public	No	Stores a transform storing the position, rotation and scale of an object

mesh		const Mesh\*	public	No	Stores a reference to a Mesh, owning the VAO, VBO and IBO

texture		const Texture\*	public	No	Stores a pointer to the Texture that the GameObject uses

shader		const Shader\*	public	No	Stores a pointer to the shader

color		Vec3		public	No	Stores the color of the GameObject



**Functions:**



**Name		Parameters			 Parameter Description**

Constructor	const Mesh\& meshRef		 The Mesh reference

&#x09;	const Texture\& textureRef	 The Texture reference

&#x09;	const Shader\& shaderRef		 The Shader reference

&#x09;	const Vec3\& colorRef = Vec3::One The Color 

Constructor	const Mesh\& meshRef		 The Mesh reference

&#x09;	const Shader\& shaderRef		 The Shader reference

&#x09;	const Vec3\& colorRef = Vec3::One The Color



**Name	 	Function Description**

Constructor	constructs a GameObject with the given parameters, when the no-texture texture constructor is used, the TextureRef is nullptr.





###### **Renderer class:**



The Renderer class is a static class that is used to render GameObjects.

Before using the renderer use 'Init', after you are done, to prevent memory leaks, use 'Shutdown'

First use 'BeginScene', then use 'Submit' to submit GameObjects to the renderer queue, then use 'EndScene' to draw everything on the back buffer.



**Variables:**



**Name		 Type				Access	Static	Description \& use**

m\_Camera	 const Camera\*			private	Yes	Camera used by the currently active scene, non-owning; camera has to stay alive until EndScene

m\_DefaultTexture Texture\*			private Yes	1x1 white texture used when a GameObject has no texture

m\_RenderQueue	 std::vector<RenderCommand>	private Yes	Commands waiting to be rendered at the end of the current scene



**Functions:**



**Name		Parameters			Parameter Description**

Init		void				/

BeginScene	const Camera\& cam		The camera that is used for this frame

Submit		const GameObject\& gameObject	The GameObject that is requested to be rendered

EndScene	void				/

Shutdown	void				/



**Name	 	Function Description**

Init		STATIC Creates the default 1x1 white Texture

BeginScene	STATIC Sets the camera used for that scene

Submit		STATIC Submits a GameObject to the RenderQueue to be rendered once EndScene is called

EndScene	STATIC Renders every object in the queue

Shutdown	STATIC Deletes the default textures and clears Renderer recources





###### **Change log:**

This is for the changes brought to the engine!



v0.1.0:

* Added Vec2 class
* Added Vec3 class
* Added Window class
* Added Transform class
* Added DeltaTime class
* Added Input class
* Added Key enum class for Input
* Added MouseButton enum class for Input
* Added VertexArrayOject class
* Added VertexBufferObject class
* Added IndexBufferObject class
* Added Shader class
* Added Mesh class
* Added Camera class
* Added Texture class
* Added VertexLayout class
* Added Renderer class
* Added RenderCommand class for Renderer
* Added GameObject class
* Added Ubrella headers for Core, Graphics, Math and for everything


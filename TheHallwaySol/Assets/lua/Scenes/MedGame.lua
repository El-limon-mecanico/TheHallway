MedGame = {
    entities = {"Maze","Player", "Minimap"}
}

Player = {
    Active = true,
    Components = {"Transform","MeshRenderer", "Rigidbody","PlayerMovement", "ProgressBar", "Health","AudioListener"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Empty.mesh",
    },

    Rigidbody = {
        Type = "Box",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0,1,0},
        RotationConstrains = {1,1,1}
    },

    ProgressBar={
        Active = true,
        Style= "TheHallway/ProgressBar",
        Name = "LighterProgress",
        Position = {0.2,0.01},
        Size = {150,50},
        Progress = 0,
        TargetResolution = {1920,1080}
    },
    PlayerMovement = 
    {
        WalkingSpeed = 13,
        RunningSpeed = 10,
        CameraSpeed = 150
    },
    Health={
        MaxLives = 3
    },
    AudioListener={},

    Children ={
        entities={"defaultCamera","WalkSound","RunSound","ScreamSounds", "Farolillo", "LuzFarol"},

        Farolillo = {
            Active = true,

            Components = {"Transform", "MeshRenderer"},

            Transform = {
                Position = {1,4,5},
                Scale = {0.5,0.5,0.5},
                Rotation = {0,90,0}
            },

            MeshRenderer = {
                Mesh = "Farolillo.mesh",   
            },
        },

        LuzFarol = {
            Active = true,

            Components = {"Transform", "Light", "Lighter"},

            Transform = {
                Position = {0,3,2},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },

            Light = {
                LightType = 0,
                DiffuseColor = {1,1,1},
                SpecularColor = {1,1,1},
                Direction = {0,0,1},
                Distance = 7000,
                InnerAngle = 35,
                OuterAngle = 60,
                isOn = true
            },
            Lighter ={
                ChargeSpeed = 0.3,
                DischargeSpeed = 0.06,
            },

            Children = {
                entities = {"LighterSound"},

                LighterSound={
                    Active=true,
                    Components={"AudioSource"},
                    AudioSource={
                        Source= "Fire.mp3",
                        Volume=1,
                        Loops=-1,
                        Play=false,
                        Enabled =true,
                        D3=false
                    }
                }

            }
        },

        defaultCamera = {

            Active = true,
            
            Components = {"Transform", "Camera", "CameraController"},
            
            Transform = {
                Position = {0,7,3},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },

            Camera = {
                Name = "MainCam",
                Background = {0,0,0},
                LookAt = {0,7,5},
                Width = 1,
                Height = 1,
                xProp = 16,
                yProp = 9,
                NearClipDistance = 1,
                FarClipDistance = 100000,
                ProjectionType = "Perspective",
                zOrder = 1
            },

            CameraController = {}

        },
        
        WalkSound={
            Active=true,
            Components={"AudioSource"},
            AudioSource={
                Source= "Steps.ogg",
                Volume=1,
                Loops=-1,
                Play=false,
                Enabled =true,
                D3=false
            },
        },

        RunSound={
            Active=true,
            Components={"AudioSource"},
            AudioSource={
                Source= "Running.ogg",
                Volume=0.4,
                Loops=-1,
                Play=false,
                Enabled =true,
                D3=false
            },
        },
        ScreamSounds={
            Active=true,
            Components={},
            Children={
                entities={"GirlScream","BoyScream"},
                GirlScream={
                    Active=true,
                    Components={"AudioSource"},
                    AudioSource={
                        Source= "GirlScream.ogg",
                        Volume=0.3,
                        Loops=0,
                        Play=false,
                        Enabled =true,
                        D3=false
                    },
                },
                BoyScream={
                    Active=true,
                    Components={"AudioSource"},
                    AudioSource={
                        Source= "BoyScream.ogg",
                        Volume=0.3,
                        Loops=0,
                        Play=false,
                        Enabled =true,
                        D3=false
                    },
                },
            }
        }
    }
}


Maze = {
    Active = true,
    Components = {"Transform", "MazeManager","AudioSource"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MazeManager = {
        Active = true,
        Size = 10,
        Holes = 15,
        Levers = 2,
	    Ghosts = 1,
        Slimes = 2,
        PointsGhosts = 6,
    },
    AudioSource={
        Source= "TheHallway.wav",
        Volume=0.1,
        Loops=-1,
        Play=true,
    }
}

Minimap = 
{
    Active = true,
    Components = {"Transform", "Camera", "MinimapController", "Image"},
    
    Transform = {
        Position = {0,100,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MinimapCam",
        Background = {0,0,0},
        LookAt = {0,0,0},
        Top = 0.05,
        Left = 0.78,
        Width = 0.2,
        Height = 0.33,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective",
        zOrder = 0
    },

    MinimapController = {}
}
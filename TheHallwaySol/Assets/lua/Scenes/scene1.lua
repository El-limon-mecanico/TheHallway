scene1 = {
    entities = {"defaultCamera","entidad1", "entidad2", "sceneLight", "UI"}
}

entidad1 = {
    Components = {"Transform", "MeshRenderer", "Rigidbody", "Prueba"},

    Transform = {
        Position = {0,5,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Suzanne.mesh",
    },

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },

    Prueba = {
        valor1 = 1,
        valor2 = 3,
        valor3 = "Quack"
    }
}

entidad2 = {
    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,-3,0},
        Scale = {5,5,1},
        Rotation = {-90,0,0}
    },

    MeshRenderer = {
        Mesh = "Plane",
    },

    Rigidbody = {
        Type = "Cube",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    }   
}

defaultCamera = {
    Components = {"Transform", "Camera"},

    Transform = {
        Position = {10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MainCam",
        Background = {1,1,0},
        LookAt = {0,0,0},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },
}

sceneLight = {
    Components = {"Transform", "Light"},

    Transform = {
        Position = {-10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        LightType = 1,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 100,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}

UI = {
    Components = {"Text1", "Image1", "Button1"},

    Text1 = {
        Type = "Text",
        Name = "Texto",
        Text = " Esto no es un boton, es solo texto, pero desde lua",
        Position = {0.5,0.05},
        Size = {405,50}
    },

    Image1 = {
        Type = "Image",
        Name = "Cuchao",
        Image = "cuchao.png",
        Position = {0.1,0.6},
        Size = {300,200}
    },

    Button1 = {
        Type = "Button",
        Name = "Button",
        Text = "Betis",
        Position = {0.5,0.5},
        Size = {100,100},
        CallBackFunction = "botonPresionado"
    },

}
Slime = {
    Active=true,
    Tag = "Enemy",
    Components = {"Transform", "MeshRenderer","Rigidbody", "MazeRunner","AudioSource"},

    Transform = {
        Position = {-10,0,0},
        Scale = {0.8,0.8,0.8},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Oozey.mesh",
    },

    Rigidbody = {
        Type = "Box",
        Mass = 1,
        Trigger = true,
        Static = false,
        PositionConstrains = {0,1,0},
        RotationConstrains = {1,1,1}
    },

    MazeRunner = {
        Speed = 8,
        Following = false,
        TimeToUpdate = 2.5,
        MaxDistance = 35
    },
    AudioSource={
        Source= "Slime.ogg",
        Volume=2,
        Loops=-1,
        Play=false,
        Enabled =true,
        D3=true
    }
}

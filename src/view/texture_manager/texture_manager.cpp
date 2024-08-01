#include "texture_manager.h"

std::shared_ptr<TextureManager> TextureManager::manager_ = nullptr;

std::shared_ptr<TextureManager> TextureManager::get_manager()
{
    if (manager_ == nullptr) 
        manager_ = std::shared_ptr<TextureManager>(new TextureManager());
        
    return manager_;
}

SDL_Texture* TextureManager::get_texture(const std::string& name) const
{
    auto it = textures_.find(prefix_ + name);
    if (it != textures_.end()) return (it->second);
    else return nullptr;
}

void TextureManager::set_renderer(SDL_Renderer* renderer) { renderer_ = renderer; }

void TextureManager::load_textures()
{
    load_all_textures_from_dir(prefix_ + "background/");
    load_all_textures_from_dir(prefix_ + "button/");
}

TextureManager::~TextureManager()
{
    for(const auto& val : textures_)
    {
        SDL_DestroyTexture(val.second);
    }
}

TextureManager::TextureManager() : prefix_("img/") { }

void TextureManager::load_all_textures_from_dir(const std::string& dir)
{
    for(const auto& file : fs::directory_iterator(dir))
    {
        if (fs::is_regular_file(file))
        {
            std::string filename = file.path().filename();
            std::string texture_name = file.path().stem();
            
            textures_[dir + texture_name] = IMG_LoadTexture(renderer_, (dir + filename).c_str());
        }
    }
}
